/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 21:46:34 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/12 02:47:47 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Private
int	PmergeMe::stringToInt(std::string str) const
{
	int					res;
	std::stringstream	ss;

	ss << str;
	ss >> res;

	return (res);
}

bool PmergeMe::isInt(const std::string& supposed_int) const
{
	if (supposed_int.empty())
		return false;
	for (size_t i = 0; i < supposed_int.length(); i++)
	{
		if ((supposed_int[i] == '-' || supposed_int[i] == '+') && i == 0)
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
	if (!isInt(supposed_int))
	{
		std::cerr << RED "ERROR => Not an int: " RESET << supposed_int << std::endl;
		return (false);
	}
	else
	{
		this->_deque.assign(stringToInt(supposed_int));
		this->_vector.assign(stringToInt(supposed_int));
	}	
}

# Public
bool	PmergeMe::sort(char **input)
{
	int	i = 1;
	while (input[i])
	{
		std::string tmp = std::string(char[i]);
		if (!addToVectorAndDeque(tmp))
			return (false);
		i++;
	}
	
	
}

PmergeMe::PmergeMe(PmergeMe& other)
{
	this->_deque = other._deque;
	this->_vector = other._vector;
}

PmergeMe& PmergeMe::operator=(PmergeMe& other)
{
	if (*this != other)
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
