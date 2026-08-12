/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 21:46:34 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/13 01:39:06 by anfouger         ###   ########.fr       */
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

bool	PmergeMe::vectorPart(int nb_input, char **input)
{
	for (int i = 1; i < nb_input; i++)
	{
		std::string tmp = std::string(input[i]);
		if (!addToVector(tmp))
			return (false);
	}
	makingVectorPair(nb_input - 1 % 2 != 0);
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
			this->_vectorPair.push_back(std::make_pair(*it, *it + 1));
	}
}

bool	PmergeMe::dequePart(int nb_input, char **input)
{
	for (int i = 1; i < nb_input; i++)
	{
		std::string tmp = std::string(input[i]);
		if (!addToDeque(tmp))
			return (false);
	}
	return (true);
}

// Public
bool	PmergeMe::sort(int nb_input, char **input)
{
	struct timeval vBefore, vAfter, dBefore, dAfter;
	
	gettimeofday(&vBefore, NULL);
	if (!vectorPart(nb_input, input))
		return (false);
	gettimeofday(&vAfter, NULL);
	
	gettimeofday(&dBefore, NULL);
	if (!dequePart(nb_input, input))
		return (false);
	gettimeofday(&dAfter, NULL);

	double us = (vAfter.tv_sec - vBefore.tv_sec) * 1000000.0
		+ (vAfter.tv_usec - vBefore.tv_usec);
	std::cout << "Time to process a range of " << nb_input - 1 
		<< " elements with std::vector: " << us << " us" << std::endl;

	us = (dAfter.tv_sec - dBefore.tv_sec) * 1000000.0
		+ (dAfter.tv_usec - dBefore.tv_usec);
	std::cout << "Time to process a range of " << nb_input - 1 
		<< " elements with std::deque: " << us << " us" << std::endl;
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
