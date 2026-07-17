/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 04:14:59 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/17 09:54:33 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array()
{
	this->array = new T[0];
	this->len = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->array = new T[n]();
	this->len = n;
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->array;
}

template <typename T>
Array<T>::Array(const Array<T>& copy)
{
	this->array = new T[copy.len];
	this->len = copy.len;
	for (size_t i = 0; i < copy.len ; i++)	
		this->array[i] = copy.array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& copy)
{
	if (this != &copy)
	{
		delete[] this->array;
		this->array = new T[copy.len];
		this->len = copy.len;
		for (size_t i = 0; i < copy.len ; i++)	
			this->array[i] = copy.array[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
	if (this->len > n)
		return this->array[n];
	throw std::exception();
}

template <typename T>
const T& Array<T>::operator[](unsigned int n) const
{
	if (this->len > n)
		return this->array[n];
	throw std::exception();
}

template <typename T>
size_t	Array<T>::size(void) const
{
	return this->len;	
}
