/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 03:18:03 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/21 05:39:12 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <stdlib.h>
# include <vector>
# include <stdexcept>
# include <algorithm>

class Span
{
private:
	unsigned int _maxSize;
	std::vector<int> _container;
public:
	Span(unsigned int N);
	Span(const Span& og);
	~Span();
	Span& operator=(const Span& og);

	void			addNumber(int nb);


	template <typename Iterator>
	void			addNumbers(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			if (this->_container.size() >= this->_maxSize)
				throw std::runtime_error("Class is full");
			this->_container.push_back(*begin);
			++begin;
		}
	}

	unsigned int	shortestSpan(void);
	unsigned int	longestSpan(void);
};

#endif