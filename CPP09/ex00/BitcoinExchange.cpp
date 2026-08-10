/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:03:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/10 23:18:15 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

/* --- Private Functions --- */

bool BitcoinExchange::isDouble(const std::string& literal) const
{
	int	flag;
	int	i;
	
	if (literal.empty())
    	return false;
	flag = 0;
	i = 0;
	if (literal[0] == '-' || literal[i] == '+')
		i++;
	while (isdigit(literal[i]))
	{
		i++;
		flag++;	
	}
	if (!flag || literal[i] != '.')
		return (false);
	i++;
	flag = 0;
	while (isdigit(literal[i]))
	{
		i++;
		flag++;
	}
	if (!flag || (unsigned long)i != literal.length())
		return (false);
	return (true);
}

bool BitcoinExchange::isInt(const std::string& literal) const
{
	if (literal.empty())
		return false;
	for (size_t i = 0; i < literal.length(); i++)
	{
		if ((literal[i] == '-' || literal[i] == '+') && i == 0)
			continue;
		if (!isdigit(literal[i]))
			return (false);
	}
	char *end;
	long test = strtol(literal.c_str(), &end, 10);
	if (*end != '\0')
		return (false);
	if (test > std::numeric_limits<int>::max() || test < std::numeric_limits<int>::min())
		return (false);
	return (true);
}

int	BitcoinExchange::stringToInt(std::string str) const
{
	int					res;
	std::stringstream	ss;

	ss << str;
	ss >> res;

	return (res);
}

bool	BitcoinExchange::isNumber(const std::string& str) const
{
	if (str.empty())
		return false;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool	BitcoinExchange::isValidDateSeparator(const std::string& date) const
{
	std::string::size_type pos_sep = date.find("-");
	pos_sep = date.find("-", pos_sep + 1);
	if (pos_sep == std::string::npos)
	{
		std::cout << RED "Error: bad input => Date doesnt have enougth separator: " RESET << date << std::endl;
		return (false);
	}
	pos_sep = date.find("-", pos_sep + 1);
	if (pos_sep != std::string::npos)
	{
		std::cout << RED "Error: bad input => Date have too much separator: " RESET << date  << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.empty())
	{
		std::cout << "Error: bad input => No date" << std::endl;
		return (false);
	}
	
	if (!isValidDateSeparator(date))
		return (false);

	std::string year_s;
	std::string month_s;
	std::string day_s;
	std::stringstream ss(date);
	std::getline(ss, year_s, '-');
	std::getline(ss, month_s, '-');
	std::getline(ss, day_s);

	if (year_s.length() != 4 || month_s.length() != 2 || day_s.length() != 2)
	{
		std::cout << RED "Error: bad input => Wrong length of date: " RESET << date << std::endl;
		return (false);
	}
	if (!isNumber(year_s) || !isNumber(month_s) || !isNumber(day_s))
	{
		std::cout << RED "Error: bad input => Not only number in date: " RESET << date << std::endl;
		return (false);
	}

	int year_i = stringToInt(year_s);
	int month_i = stringToInt(month_s);
	int day_i = stringToInt(day_s);
	if (month_i < 1 || month_i > 12)
	{
		std::cout << RED "Error: bad input => Month not acceptable: " RESET << year_s << YELLOW << month_s << RESET << day_s << std::endl;
		return (false);
	}
	if (day_i < 1 || day_i > 31)
	{
		std::cout << RED "Error: bad input => Day not acceptable: " RESET << year_s << month_s << YELLOW << day_s << RESET << std::endl;
		return (false);
	}
	if (month_i == 2)
	{
		if (day_i > 29)
		{
			std::cout << RED "Error: bad input => Day not acceptable: " RESET << year_s << month_s << YELLOW << day_s << RESET << std::endl;
			return (false);
		}
		if (day_i == 29 && !((year_i % 400 == 0) | (year_i % 4 == 0 && year_i % 100 != 0)))
		{
			std::cout << RED "Error: bad input => Day not acceptable: " RESET << year_s << month_s << YELLOW << day_s << RESET << std::endl;
			return (false);
		}
	}
	if (day_i == 31)
	{
		if (month_i != 1 && month_i != 3 && month_i != 5 &&
			month_i != 7 && month_i != 8 && month_i != 10 && month_i != 12)
		{
			std::cout << RED "Error: bad input => Day not acceptable: " RESET << year_s << month_s << YELLOW << day_s << RESET << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	BitcoinExchange::isValidValue(const std::string& value) const
{
	if (!isInt(value) && !isDouble(value))
	{
		std::cout << RED "Error: bad input => Value not acceptable: " RESET << value << std::endl;
		return (false);	
	}
	return (true);
}

std::string::size_type BitcoinExchange::isValidLine(const std::string& line) const
{
	std::string::size_type pos = line.find(" | ");
	std::string::size_type res = pos;
	if (pos == std::string::npos)
	{
		std::cout << RED "Error: bad input => No separator found: " RESET << line << std::endl;
		return (0);
	}
	pos = line.find(" | ", pos + 3);
	if (pos != std::string::npos)
	{
		std::cout << RED "Error: bad input => Too much separator found" RESET << line << std::endl;
		return (0);
	}
	return (res);
}

double BitcoinExchange::getExchangeRate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator	it;

	it = _database.lower_bound(date);
	if (it == _database.end() || (it != _database.begin() && it->first > date))
		--it;
	else if (it == _database.begin() && it->first != date)
		throw DoesntHaveRateException();
	return (it->second);
}

/* --- Public Functions --- */
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->_database = other._database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		this->_database = other._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::string line;
	std::ifstream file(filename.c_str());
	if (!file)
	{
		std::cout << RED "Error: Couldn't open file named " RESET << filename << std::endl;
		return ;
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string date;
		std::string rate;
		std::stringstream ss(line);

		std::getline(ss, date, ',');
		std::getline(ss, rate);
		double exchangeRate = std::strtod(rate.c_str(), 0);
		this->_database.insert(std::make_pair(date, exchangeRate));
	}
}

void BitcoinExchange::processInput(const std::string& filename)
{
	std::string line;
	std::ifstream file(filename.c_str());
	if (!file)
	{
		std::cout << RED "Error: Couldn't open file named " RESET << filename << std::endl;
		return ;
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string::size_type pos = isValidLine(line);
		if (!pos)
			continue;

		std::string date;
		std::string value;

		date = line.substr(0, pos);
		value = line.substr(pos + 3);
		if (!isValidDate(date))
    		continue;
		if (!isValidValue(value))
			continue;

		try
		{
			double exchangeRate = getExchangeRate(date);
			double finalValue = std::strtod(value.c_str(), 0);
			if (finalValue < 0 || finalValue > 1000)
				throw OffLimitsException();
			std::cout << date << " => " << finalValue << " = " << finalValue * exchangeRate << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << line << '\n';
		}
	}
}
