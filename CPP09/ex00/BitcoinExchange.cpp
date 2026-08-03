/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:03:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/03 16:14:14 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

/* --- Private Functions --- */

bool	BitcoinExchange::isValidDate(std::string date)
{
	(void)date;
	return (false);
}

bool	BitcoinExchange::isValidValue(double value)
{
	(void)value;
	return (false);
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

void BitcoinExchange::loadDatabase(std::string filename)
{
	(void)filename;
}

void BitcoinExchange::processInput(std::string filename)
{
	(void)filename;	
}
