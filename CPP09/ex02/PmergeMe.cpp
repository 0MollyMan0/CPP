/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 21:46:34 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/13 00:39:20 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Private
void	PmergeMe::swapPair(std::pair<int, int> _pair)
{
	int tmp = _pair.first;
	_pair.first = _pair.second;
	_pair.second = tmp;
}

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
		if (!std::isdigit(supposed_int[i]))
			return (false);
	}
	char *end;
	long test = strtol(supposed_int.c_str(), &end, 10);
	if (*end != '\0' || test <= 0)
		return (false);
	if (test > std::numeric_limits<int>::max() || test < std::numeric_limits<int>::min())
		return (false);
	return (true);
}

bool	PmergeMe::addToDeque(std::string& supposed_int)
{
	if (!isPositiveInt(supposed_int))
	{
		std::cerr << RED "ERROR => Not a positive int: " RESET << supposed_int << std::endl;
		return (false);
	}
	else
		this->_deque.push_back(stringToInt(supposed_int));
	return (true);
}

bool	PmergeMe::addToVector(std::string& supposed_int)
{
	if (!isPositiveInt(supposed_int))
	{
		std::cerr << RED "ERROR => Not a positive int: " RESET << supposed_int << std::endl;
		return (false);
	}
	else
		this->_vector.push_back(stringToInt(supposed_int));
	return (true);
}

bool	PmergeMe::vectorPart(char **input)
{
	int	i = 1;
	while (input[i])
	{
		std::string tmp = std::string(input[i]);
		if (!addToVector(tmp))
			return (false);
		i++;
	}
	makingVectorPair(i - 1 % 2 != 0);
	return (true);
}

void	PmergeMe::makingVectorPair(bool straggler)
{
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it+=2)
	{
		if (straggler && it + 1 == this->_vector.end())
		{
			this->_vectorStraggler = *it;
			break;
		}
		else
			this->_vectorPair.push_back(*it, *it + 1);
	}
}

bool	PmergeMe::dequePart(char **input)
{
	int i = 1;
	while (input[i])
	{
		std::string tmp = std::string(input[i]);
		if (!addToDeque(tmp))
			return (false);
		i++;
	}
	return (true);
}

// Public
bool	PmergeMe::sort(char **input)
{
	if (!vectorPart(input))
		return (false);
	if (!dequePart(input))
		return (false);
	return (true);
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	this->_deque = other._deque;
	this->_vector = other._vector;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
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
