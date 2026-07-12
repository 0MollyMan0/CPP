/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:45:20 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/12 14:03:08 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"
#include "./utils.hpp"
#include <limits.h>
#include <iostream>
#include <cmath>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void	ScalarConverter::convert(const std::string& literal)
{
	std::cout << "Input literal: " << literal << std::endl;
	switch (detectType(literal))
	{
	case CHAR:
	{
		double value = literal[1];
		displayConversions(value);
		break;
	}

	case PSEUDO:
	{
		printPseudo(literal);
		break;
	}

	case FLOAT:
	{
		char *end;
		double value = strtod(literal.c_str(), &end);
		displayConversions(value);
		break;
	}

	case DOUBLE:
	{
		char *end;
		double value = strtod(literal.c_str(), &end);
		displayConversions(value);
		break;
	}

	case INT:
	{
		char *end;
		double value = strtod(literal.c_str(), &end);
		displayConversions(value);
		break;
	}
	default:
		break;
	}
}

void ScalarConverter::displayConversions(double value)
{
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::printPseudo(const std::string& value)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (value == "nan" || value == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (value == "+inf" || value == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void ScalarConverter::printChar(double value)
{
	if (value < std::numeric_limits<char>::min()
		|| value > std::numeric_limits<char>::max())
	{
		std::cout << "char: impossible" << std::endl;
		return ;	
	}
	char c = static_cast<char>(value);
	if (isprint(c))
		std::cout << "char: " << "\'" << c << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}
void ScalarConverter::printInt(double value)
{
	if (value > std::numeric_limits<int>::max()
        || value < std::numeric_limits<int>::min())
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    std::cout << "int: " << static_cast<int>(value) << std::endl;
}
void ScalarConverter::printFloat(double value)
{
	if (value != std::floor(value))
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
}
void ScalarConverter::printDouble(double value)
{
	if (value != std::floor(value))
		std::cout << "double: " << value << std::endl;
	else
		std::cout << "double: " << value << ".0" << std::endl;
}

LiteralType	ScalarConverter::detectType(const std::string& literal)
{
	if (isCharLiteral(literal))
		return CHAR;

	if (isPseudoLiteral(literal))
		return PSEUDO;

	if (isFloat(literal))
		return FLOAT;

	if (isDouble(literal))
		return DOUBLE;

	if (isInt(literal))
		return INT;

	return (INVALID);
}

bool ScalarConverter::isFloat(const std::string& literal)
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
	if (!flag || literal[i] != 'f' || (unsigned long)i != literal.length() - 1)
		return (false);
	return (true);
}

bool ScalarConverter::isDouble(const std::string& literal)
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
	
bool ScalarConverter::isInt(const std::string& literal)
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

bool ScalarConverter::isPseudoLiteral(const std::string& literal)
{
    return (
		literal == "nan"
		|| literal == "nanf"
		|| literal == "+inf"
		|| literal == "+inff"
		|| literal == "-inf"
		|| literal == "-inff"
    );
}

bool ScalarConverter::isCharLiteral(const std::string& literal)
{
	return (
		literal.length() == 3
		&& literal[0] == '\''
		&& literal[2] == '\''
	);
}

