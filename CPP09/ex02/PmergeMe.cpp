/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 21:46:34 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/20 03:33:57 by anfouger         ###   ########.fr       */
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

std::vector<size_t> PmergeMe::generateJacobsthal(size_t size)
{
    std::vector<size_t> jacob;

    jacob.push_back(0);
    jacob.push_back(1);

    while (jacob.back() < size)
    {
        size_t n = jacob.size();

        jacob.push_back(
            jacob[n - 1] + 2 * jacob[n - 2]
        );
    }

    return (jacob);
}

// === Vector === //

std::vector<size_t> PmergeMe::getInsertionOrder(size_t size)
{
    std::vector<size_t> order;

    if (size == 0)
        return (order);

    order.push_back(1);

    size_t previous = 1;
    size_t current = 3;

    while (previous < size)
    {
        size_t end = current;

        if (end > size)
            end = size;

        for (size_t i = end; i > previous; --i)
            order.push_back(i);

        size_t next = current + 2 * previous;
        previous = current;
        current = next;
    }

    return (order);
}

void	displayVector(std::vector<int> vector)
{
	for (std::vector<int> ::iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

std::vector<int> PmergeMe::getBigFromVector(std::vector<std::pair<int, int> >& vectorPair)
{
	std::vector<int> res;
	for (std::vector<std::pair<int, int> >::iterator it = vectorPair.begin();
			it != vectorPair.end();
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
	this->_vector = fordJohnsonVector(this->_vector);
	return (true);
}

std::vector<std::pair<int, int> > PmergeMe::makingVectorPair(std::vector<int>& vector, bool& hasStraggler, int& straggler)
{
	std::vector<std::pair<int, int> > vectorPair;

	hasStraggler = false;

	for (std::vector<int>::iterator it = vector.begin();
		 it != vector.end();
		 it += 2)
	{
		if (it + 1 == vector.end())
		{
			hasStraggler = true;
			straggler = *it;
			break;
		}

		if (*it <= *(it + 1))
			vectorPair.push_back(std::make_pair(*it, *(it + 1)));
		else
			vectorPair.push_back(std::make_pair(*(it + 1), *it));
	}

	return (vectorPair);
}

std::vector<int> PmergeMe::insertSmallVector(std::vector<int>& vector, int small, int big)
{
	std::vector<int>::iterator bigPos;
	std::vector<int>::iterator insertPos;

	bigPos = std::find(vector.begin(), vector.end(), big);
	insertPos = std::lower_bound(vector.begin(), bigPos, small);
	vector.insert(insertPos, small);

	return (vector);
}

std::vector<int> PmergeMe::fordJohnsonVector(std::vector<int> big)
{
	if (big.size() < 2)
		return (big);
	
	bool hasStraggler = false;
	int straggler = 0;
	std::vector<std::pair<int, int> > vectorPair;
	std::vector<int> sorted;

	vectorPair = makingVectorPair(big, hasStraggler, straggler); 
	big = getBigFromVector(vectorPair);
	sorted = fordJohnsonVector(big);

	std::vector<size_t> order = getInsertionOrder(vectorPair.size());
	for (std::vector<size_t>::iterator it = order.begin(); it != order.end(); ++it)
	{
		size_t index = *it - 1;
		sorted = insertSmallVector(sorted, vectorPair[index].first, vectorPair[index].second);
	}

	if (hasStraggler)
	{
		std::vector<int>::iterator pos =
			std::lower_bound(sorted.begin(), sorted.end(), straggler);

		sorted.insert(pos, straggler);
	}

	return (sorted);
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
	// struct timeval vBefore, vAfter, dBefore, dAfter;

	// gettimeofday(&vBefore, NULL);
	if (!vectorPart(nb_input, input))
		return (false);
	// gettimeofday(&vAfter, NULL);
	
	// gettimeofday(&dBefore, NULL);
	if (!dequePart(nb_input, input))
		return (false);
	// gettimeofday(&dAfter, NULL);

	std::cout << "Before: ";
	for (int i = 1; i < nb_input; i++)
		std::cout << input[i] << " ";
	std::cout << std::endl;
	
	// std::cout << "After Making Pair: ";
	// for (std::vector<std::pair<int, int> > ::iterator it = this->_vectorPair.begin(); 
	// 		it != this->_vectorPair.end();
	// 		it++)
	// 	std::cout << "(" << it->first << ", " << it->second << ") ";
	// std::cout << std::endl;

	std::cout << "After: ";
	for (std::vector<int> ::iterator it = this->_vector.begin(); 
			it != this->_vector.end();
			it++)
		std::cout << *it << " ";
	// if (this->_hasVectorStraggler)
	// 	std::cout << this->_vectorStraggler;
	std::cout << std::endl;

	// double us = getDiffInUs(vBefore, vAfter);
	// std::cout << "Time to process a range of " << nb_input - 1 
	// 	<< " elements with std::vector: " << us << " us" << std::endl;

	// us = getDiffInUs(dBefore, dAfter);
	// std::cout << "Time to process a range of " << nb_input - 1 
	// 	<< " elements with std::deque: " << us << " us" << std::endl;
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
