/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:02:27 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/10 23:18:29 by anfouger         ###   ########.fr       */
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

# define RESET "\033[0m"
# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
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
				return RED "Doesnt have rate for this date in the database: " RESET;
			}
	};

	class OffLimitsException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return RED "Not in range limit (0 - 1000): " RESET;
			}
	};

	void loadDatabase(const std::string& filename);
	void processInput(const std::string& filename);
};

#endif