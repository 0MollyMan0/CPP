/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:45:20 by anfouger          #+#    #+#             */
/*   Updated: 2026/06/24 14:54:54 by anfouger         ###   ########.fr       */
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
		std::cout << "CHAR detected" << std::endl;
		break;

	case PSEUDO:
		std::cout << "PSEUDO detected" << std::endl;
		break;

	case FLOAT:
		std::cout << "FLOAT detected" << std::endl;
		break;

	case DOUBLE:
		std::cout << "DOUBLE detected" << std::endl;
		break;

	case INT:
		std::cout << "INT detected" << std::endl;
		break;

	case INVALID:
		std::cout << "INVALID detected" << std::endl;
		break;
	default:
		break;
	}
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
	if (literal[0] == '-')
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
	if (literal[0] == '-')
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
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (!isdigit(literal[i])
			&& (literal[i] != '-' && i == 0))
			return (false);
	}
	char *end;
	long test = strtol(literal.c_str(), &end, 10);
	if (*end != '\0')
		return (false);
	if (test > INT_MAX || test < INT_MIN)
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
