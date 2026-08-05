/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:02:27 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/05 12:16:31 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <stdlib.h>
# include <map>
# include <string>
# include <iostream>
# include <sstream>
# include <fstream>

class BitcoinExchange
{
private:
	std::map<std::string, double> _database;

	bool isValidDate(std::string& date) const;
	bool isValidValue(double value) const;
	double getExchangeRate(const std::string& date) const;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void loadDatabase(const std::string& filename);
	void processInput(const std::string& filename);
};

#endif