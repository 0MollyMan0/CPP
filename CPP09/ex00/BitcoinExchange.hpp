/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:02:27 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/09 18:28:13 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <stdlib.h>
# include <map>
# include <string.h>
# include <iostream>
# include <sstream>
# include <fstream>
# include <exception>
# include <limits>
class BitcoinExchange
{
private:
	std::map<std::string, double> _database;

	bool isInt(const std::string& literal) const;
	bool isDouble(const std::string& literal) const;
	int	stringToInt(std::string str) const;
	bool isNumber(const std::string& str) const;
	bool isValidDate(const std::string& date) const;
	bool isValidDateSeparator(const std::string& date) const;
	bool isValidValue(const std::string& value) const;
	std::string::size_type isValidLine(const std::string& line) const;
	double getExchangeRate(const std::string& date) const;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	class DoesntHaveRateException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Doesnt have rate for this date in the database";
			}
	};

	class OffLimitsException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Not in range limit (0 - 1000)";
			}
	};

	void loadDatabase(const std::string& filename);
	void processInput(const std::string& filename);
};

#endif