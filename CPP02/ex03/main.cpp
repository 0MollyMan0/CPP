/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:15:02 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/11 13:49:54 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

static float stringToFloat(const std::string& str)
{
    std::stringstream ss(str);
    float value = 0.0f;
    ss >> value;
    return value;
}

static bool	isFloat(const std::string& str)
{
	if (str.empty())
		return false;

	size_t i = 0;
	bool hasDot = false;
	bool hasDigit = false;
	
	if (str[i] == '+' || str[i] == '-')
		i++;
		
	for (; i < str.length(); i++)
	{
		if (std::isdigit(str[i]))
			hasDigit = true;
		else if (str[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else
			return false;
	}
	
	return hasDigit;
}


static bool verifParsing(int ac, char **av)
{
	if (ac < 9)
		return (false);
	for (int i = 1; i < ac; i++)
	{
		if(!isFloat(av[i]))
			return (false);	
	}
	return (true);
}

int main(int ac, char **av) 
{
	if (!verifParsing(ac, av))
	{
		std::cout << "wrong args";
		return (1);
	}
	
	const Point a(stringToFloat(av[1]), stringToFloat(av[2]));
	const Point b(stringToFloat(av[3]), stringToFloat(av[4]));
	const Point c(stringToFloat(av[5]), stringToFloat(av[6]));
	const Point point(stringToFloat(av[7]), stringToFloat(av[8]));

	if (bsp(a, b, c, point))
		std::cout << "the point is in the triangle";
	else
		std::cout << "the point isnt in the triangle";
	return 0;
}
