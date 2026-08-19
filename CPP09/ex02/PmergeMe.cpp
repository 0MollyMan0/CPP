/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 21:46:34 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/14 02:13:19 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ==== PRIVATE ==== //

// === Utils === //
double	PmergeMe::getDiffInUs(timeval before, timeval after)
{
	return((after.tv_sec - before.tv_sec) * 1000000.0
		+ (after.tv_usec - before.tv_usec));
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
	if (test > std::numeric_limits<int>::max())
		return (false);
	return (true);
}

// === Vector === //

std::vector<int> PmergeMe::getBigFromVector(void)
{
	std::vector<int> res;
	for (std::vector<std::pair<int, int> >::iterator it = this->_vectorPair.begin();
			it != this->_vectorPair.end();
			it++)
	{
		res.push_back(it->second);
	}
	return (res);
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
	makingVectorPair((nb_input - 1) % 2 != 0);
	std::vector<int> big = getBigFromVector();
	return (true);
}

void	PmergeMe::makingVectorPair(bool straggler)
{
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it+=2)
	{
		if (straggler && it + 1 == this->_vector.end())
		{
			this->_hasVectorStraggler = true;
			this->_vectorStraggler = *it;
			break;
		}
		else
		{
			if (*it <= *(it + 1))
				this->_vectorPair.push_back(std::make_pair(*it, *(it + 1)));
			else
				this->_vectorPair.push_back(std::make_pair(*(it + 1), *it));	
		}
	}
}

// === Deque === //

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

// ==== PUBLIC ==== //
bool	PmergeMe::sort(int nb_input, char **input)
{
	struct timeval vBefore, vAfter, dBefore, dAfter;
	this->_hasVectorStraggler = false;

	gettimeofday(&vBefore, NULL);
	if (!vectorPart(nb_input, input))
		return (false);
	gettimeofday(&vAfter, NULL);
	
	gettimeofday(&dBefore, NULL);
	if (!dequePart(nb_input, input))
		return (false);
	gettimeofday(&dAfter, NULL);

	std::cout << "Before: ";
	for (int i = 1; i < nb_input; i++)
		std::cout << input[i] << " ";
	std::cout << std::endl;
	
	std::cout << "After Making Pair: ";
	for (std::vector<std::pair<int, int> > ::iterator it = this->_vectorPair.begin(); 
			it != this->_vectorPair.end();
			it++)
		std::cout << "(" << it->first << ", " << it->second << ") ";
	if (this->_hasVectorStraggler)
		std::cout << this->_vectorStraggler;
	std::cout << std::endl;

	std::cout << "After: ";
	for (std::vector<int> ::iterator it = this->_vector.begin(); 
			it != this->_vector.end();
			it++)
		std::cout << *it << " ";
	if (this->_hasVectorStraggler)
		std::cout << this->_vectorStraggler;
	std::cout << std::endl;

	double us = getDiffInUs(vBefore, vAfter);
	std::cout << "Time to process a range of " << nb_input - 1 
		<< " elements with std::vector: " << us << " us" << std::endl;

	us = getDiffInUs(dBefore, dAfter);
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
