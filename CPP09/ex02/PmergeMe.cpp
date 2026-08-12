/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 21:46:34 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/12 23:29:25 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Private
int	PmergeMe::stringToInt(const std::string& str) const
{
	int					res;
	std::stringstream	ss;

	ss << str;
	ss >> res;

	return (res);
}

bool PmergeMe::isPositiveInt(const std::string& supposed_int) const
{
	if (supposed_int.empty())
		return false;
	for (size_t i = 0; i < supposed_int.length(); i++)
	{
		if (supposed_int[i] == '+' && i == 0)
			continue;
		if (!isdigit(supposed_int[i]))
			return (false);
	}
	char *end;
	long test = strtol(supposed_int.c_str(), &end, 10);
	if (*end != '\0')
		return (false);
	if (test > std::numeric_limits<int>::max() || test < std::numeric_limits<int>::min())
		return (false);
	return (true);
}

bool	PmergeMe::addToVectorAndDeque(std::string& supposed_int)
{
	if (!isPositiveInt(supposed_int))
	{
		std::cerr << RED "ERROR => Not a positive int: " RESET << supposed_int << std::endl;
		return (false);
	}
	else
	{
		this->_deque.push_back(stringToInt(supposed_int));
		this->_vector.push_back(stringToInt(supposed_int));
	}	
	return (true);
}

// Public
bool	PmergeMe::sort(char **input)
{
	int	i = 1;
	while (input[i])
	{
		std::string tmp = std::string(input[i]);
		if (!addToVectorAndDeque(tmp))
			return (false);
		i++;
	}
	
	return (true);
}

PmergeMe::PmergeMe(PmergeMe& other)
{
	this->_deque = other._deque;
	this->_vector = other._vector;
}

PmergeMe& PmergeMe::operator=(PmergeMe& other)
{
	if (this != &other)
	{
		this->_deque = other._deque;
		this->_vector = other._vector;
	}
	return (*this);
}

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}
