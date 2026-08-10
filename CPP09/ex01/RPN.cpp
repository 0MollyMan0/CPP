/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:31:29 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/11 00:14:13 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Usefull
int		RPN::charToFigure(char c) const
{
	if (!c)
		return (false);
	for (size_t i = 0; i <= 9; i++)
	{
		if (i + 48 == c)
			return (i);
	}
	return (-1);
}

void	RPN::createStack(std::string& input)
{
	if (input.empty())
	{
		std::cout << RED "Error => Input is empty" RESET << std::endl;
		return ;
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		if (i % 2 == 0)
		{
			if (!std::isdigit(input[i]) && input[i] != '-' && input[i] != '*' && input[i] != '/' && input[i] != '+')
			{
				std::cout << RED "Error => Character not accepeted: " RESET << input[i] << std::endl;
				return ;
			}
			this->_stack.push(charToFigure(input[i]));
		}
		else
		{
			if (input[i] != ' ')
			{
				std::cout << RED "Error => Missing space: " RESET << input[i] << std::endl;
				return ;
			}
		}
	}
}

void	RPN::letMeCook()
{
	
}


// Not interesting

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
	this->_stack = other._stack;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		this->_stack = other._stack;
	return (*this);
}

RPN::~RPN()
{
}
