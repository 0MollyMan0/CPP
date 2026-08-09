/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:03:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/09 15:05:57 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

/* --- Private Functions --- */

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

bool	BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.empty())
	{
		std::cout << "Error: bad input => No date" << std::endl;
		return (false);
	}

	std::string::size_type pos_sep = date.find("-");
	pos_sep = date.find("-", pos_sep + 1);
	if (pos_sep == std::string::npos)
	{
		std::cout << "Error: bad input => Date doesnt have enougth separator" << std::endl;
		return (false);
	}

	std::string year_s;
	std::string month_s;
	std::string day_s;
	std::stringstream ss(date);
	std::getline(ss, year_s, '-');
	std::getline(ss, month_s, '-');
	std::getline(ss, day_s);

	if (year_s.length() != 4 || month_s.length() != 2 || day_s.length() != 2)
	{
		std::cout << "Error: bad input => Wrong length of date" << std::endl;
		return (false);
	}
	if (!isNumber(year_s) || !isNumber(month_s) || !isNumber(day_s))
	{
		std::cout << "Error: bad input => Not only number in date" << std::endl;
		return (false);
	}

	int year_i = stringToInt(year_s);
	int month_i = stringToInt(month_s);
	int day_i = stringToInt(day_s);
	if (year_i < 2009 || year_i > 2027)
	{
		std::cout << "Error: bad input => Year not acceptable" << std::endl;
		return (false);
	}
	if (month_i < 1 || month_i > 12)
	{
		std::cout << "Error: bad input => Month not acceptable" << std::endl;
		return (false);
	}
	if (day_i < 1 || day_i > 31)
	{
		std::cout << "Error: bad input => Day not acceptable" << std::endl;
		return (false);
	}
	if (month_i == 2)
	{
		if (day_i > 29)
		{
			std::cout << "Error: bad input => Day not acceptable" << std::endl;
			return (false);
		}
		// verif february with modulo and all that shit
	}
	if (day_i == 31 && month_i % 2 != 1)
	{
		std::cout << "Error: bad input => Day not acceptable" << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::isValidValue(const std::string& value) const
{
	if (value.empty())
	{
		std::cout << "Error: bad input => No value" << std::endl;
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
		std::cout << "Error: bad input => No separator found" << std::endl;
		return (0);
	}
	pos = line.find(" | ", pos + 3);
	if (pos != std::string::npos)
	{
		std::cout << "Error: bad input => Too much separator found" << std::endl;
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
		std::cout << "Couldn't open file named " << filename << std::endl;
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
		std::cout << "Error: could not open file." << std::endl;
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
			std::cout << date << " => " << finalValue << " = " << finalValue * exchangeRate << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
