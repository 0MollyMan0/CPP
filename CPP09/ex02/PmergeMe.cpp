/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 21:46:34 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/12 02:26:40 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Private
bool PmergeMe::isInt(const std::string& literal) const
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

bool	PmergeMe::createVectorAndDeque(char **argv)
{
	
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
