/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:45:20 by anfouger          #+#    #+#             */
/*   Updated: 2026/06/23 11:55:47 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"
#include "./utils.hpp"
#include <limits>
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
	if (isCharLiteral(literal))
	{
		std::cout << "char detected" << std::endl;
		return;
	}
}

bool ScalarConverter::isCharLiteral(const std::string& literal)
{
	return (
		literal.length() == 3 
		&& literal[0] == '\'' 
		&& literal[2] == '\''
	);
}
