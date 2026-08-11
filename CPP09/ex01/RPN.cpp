/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:31:29 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/11 02:11:36 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Private
int		RPN::charToFigure(char c) const
{
	if (!c)
		return (false);
	for (int i = 0; i <= 9; i++)
	{
		if (i + 48 == c)
			return (i);
	}
	return (-1);
}

bool	RPN::doDiv(void)
{
	int right = this->_stack.top();
	this->_stack.pop();
	int	left  = this->_stack.top();
	this->_stack.pop();

	if (right == 0)
	{
		std::cerr << RED "Error => Can't do a division by 0" RESET << std::endl;
		return (false);
	}
	
	long result = left / right;
	if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
	{
		std::cerr << RED "Error => Result of operation is out of bound for int: " RESET << left << " / " << right << std::endl;
		return (false);	
	}
	this->_stack.push(result);
	return (true);
}

bool	RPN::doAdd(void)
{
	int right = this->_stack.top();
	this->_stack.pop();
	int	left  = this->_stack.top();
	this->_stack.pop();

	long result = left + right;
	if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
	{
		std::cerr << RED "Error => Result of operation is out of bound for int: " RESET << left << " / " << right << std::endl;
		return (false);	
	}
	this->_stack.push(result);
	return (true);
}

bool	RPN::doMult(void)
{
	int right = this->_stack.top();
	this->_stack.pop();
	int	left  = this->_stack.top();
	this->_stack.pop();

	long result = left * right;
	if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
	{
		std::cerr << RED "Error => Result of operation is out of bound for int: " RESET << left << " / " << right << std::endl;
		return (false);	
	}
	this->_stack.push(result);
	return (true);
}

bool	RPN::doSub(void)
{
	int right = this->_stack.top();
	this->_stack.pop();
	int	left  = this->_stack.top();
	this->_stack.pop();

	long result = left - right;
	if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
	{
		std::cerr << RED "Error => Result of operation is out of bound for int: " RESET << left << " / " << right << std::endl;
		return (false);	
	}
	this->_stack.push(result);
	return (true);
}

// Public
bool	RPN::verifyStack(std::string& input)
{
	if (input.empty())
	{
		std::cerr << RED "Error => Input is empty" RESET << std::endl;
		return (false);
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		if (i % 2 == 0)
		{
			if (!std::isdigit(input[i]) && input[i] != '-' && input[i] != '*' && input[i] != '/' && input[i] != '+')
			{
				std::cerr << RED "Error => Character not accepeted: " RESET << input[i] << std::endl;
				return (false);
			}
		}
		else
		{
			if (input[i] != ' ')
			{
				std::cerr << RED "Error => Missing space: " RESET << input[i] << std::endl;
				return (false);
			}
		}
	}
	return (true);
}

void	RPN::calculate(std::string& input)
{
	if (!verifyStack(input))
		return ;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (i % 2 == 0)
		{
			if (std::isdigit(input[i]))
			{
				this->_stack.push(charToFigure(input[i]));
				continue ;	
			}
			if (this->_stack.size() < 2)
			{
				std::cerr << RED "Error => Not enougth figure to calculate" RESET << std::endl;
				return ;
			}
			switch (input[i])
			{
				case '+':
					if (!doAdd())
						return ;
					break;
				
				case '-':
					if (!doSub())
						return ;
					break;

				case '*':
					if (!doMult())
						return ;
					break;

				case '/':
					if (!doDiv())
						return ;
					break;
				
				default:
					break;
			}
		}
	}
	if (this->_stack.size() != 1)
	{
		std::cerr << RED "Error => There's " << this->_stack.size() << " elements left" RESET << std::endl;
		return ;
	}
	std::cerr << this->_stack.top() << std::endl;
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
