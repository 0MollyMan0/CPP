/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 03:18:49 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/21 05:41:23 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N)
{
	this->_maxSize = N;
}

Span::Span(const Span& og)
{
	this->_container = og._container;
	this->_maxSize = og._maxSize;
}

Span::~Span()
{
}

void			Span::addNumber(int nb)
{
	if (this->_container.size() >= this->_maxSize)
		throw std::runtime_error("Class is full");
	else
		this->_container.push_back(nb);
}

unsigned int	Span::shortestSpan(void)
{
	if (this->_container.size() <= 1)
		throw std::runtime_error("Not enougth number in class");

	std::vector<int>	sorted = this->_container;
	std::sort(sorted.begin(), sorted.end());
	std::vector<int>::iterator it = sorted.begin();
	unsigned int		shortest;
	unsigned int		tmp;
	
	shortest = *(it + 1) - *it;
	while (it + 1 != sorted.end())
	{
		tmp = *(it + 1) - *it;
		if (tmp < shortest)
			shortest = tmp;
		++it;
	}
	return (shortest);
}

Span& Span::operator=(const Span& og)
{
	if (this != &og)
	{
		this->_container = og._container;
		this->_maxSize = og._maxSize;
	}
	return (*this);
}

unsigned int	Span::longestSpan(void)
{
	if (this->_container.size() <= 1)
		throw std::runtime_error("Not enougth number in class");
	std::vector<int>::iterator maxIt = std::max_element(this->_container.begin(), this->_container.end());
	std::vector<int>::iterator minIt = std::min_element(this->_container.begin(), this->_container.end());
	return (*maxIt - *minIt);
}
