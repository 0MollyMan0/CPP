/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:03:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/09 12:48:42 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

/* --- Private Functions --- */

bool	BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.empty())
	{
		std::cout << "Error: bad input => No date" << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::isValidLine(const std::string& line) const
{
	std::string::size_type pos = line.find(" | ");
	if (pos == std::string::npos)
	{
		std::cout << "Error: bad input => No separator found" << std::endl;
		return (false);
	}
	pos = line.find(" | ", pos + 3);
	if (pos != std::string::npos)
	{
		std::cout << "Error: bad input => Too much separator found" << std::endl;
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
		if (!isValidLine(line))
			continue;

		std::stringstream ss(line);
		std::string date;
		std::string value;

		std::getline(ss, date, '|');
		std::getline(ss, value);

		if (!isValidDate(date))
    		continue;
		if (!isValidValue(value))
			continue;

		try
		{
			double exchangeRate = getExchangeRate(date);
			double finialValue = std::strtod(value.c_str(), 0);
			std::cout << finialValue * exchangeRate << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
