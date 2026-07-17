/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 02:49:17 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/17 09:54:38 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <stdlib.h>

template <typename T>
class Array
{
private:
	T		*array;
	size_t	len;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& copy);
	Array& operator=(const Array& copy);
	T& operator[](unsigned int n);
	const T& operator[](unsigned int n) const;
	~Array();
	size_t	size() const;
};

# include "Array.tpp"

#endif