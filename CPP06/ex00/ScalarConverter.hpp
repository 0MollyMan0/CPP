/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:45:39 by anfouger          #+#    #+#             */
/*   Updated: 2026/06/24 16:02:19 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string.h>
# include "./utils.hpp"

enum LiteralType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    INVALID
};
class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	static LiteralType detectType(const std::string& literal);
	static void printChar(double value);
	static void printInt(double value);
	static void printFloat(double value);
	static void printDouble(double value);
	static void displayConversions(double value);
	static bool isFloat(const std::string& literal);
	static bool isDouble(const std::string& literal);
	static bool isInt(const std::string& literal);
	static bool isPseudoLiteral(const std::string& literal);
	static bool isCharLiteral(const std::string& literal);
public:
	static void	convert(const std::string& literal);
};


#endif