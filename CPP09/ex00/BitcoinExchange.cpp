/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:03:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/05 12:34:06 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

/* --- Private Functions --- */

bool	BitcoinExchange::isValidDate(std::string& date) const
{
	(void)date;
	return (false);
}

bool	BitcoinExchange::isValidValue(double value) const
{
	(void)value;
	return (false);
}

double BitcoinExchange::getExchangeRate(const std::string& date) const
{
	(void)date;
	return (0);
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
		this->_database.insert(std::make_pair(date, std::strtod(rate.c_str(), 0)));
	}
}

void BitcoinExchange::processInput(const std::string& filename)
{
	(void)filename;	
}
