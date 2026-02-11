/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:14:43 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/10 13:28:05 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	this->_raw = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw = value << _fractionalBits;
}

Fixed::Fixed(float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_raw = (int)roundf(value * (1 <<_fractionalBits));
}

Fixed::Fixed(const Fixed& other) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_raw = other._raw;
	}
	return *this;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result(this->_raw + other._raw);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result(this->_raw - other._raw);
	return result;
}

Fixed& Fixed::operator++(void)
{
	this->_raw++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed result(*this);
	this->_raw++;
	return result;
}

Fixed& Fixed::operator--(void)
{
	this->_raw--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed result(*this);
	this->_raw--;
	return result;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_raw;
}

void	Fixed::setRawBits(int raw)
{
	this->_raw = raw;
}

float Fixed::toFloat() const
{
	return ((float)this->_raw / (1 <<_fractionalBits));
}

int Fixed::toInt() const
{
	return this->_raw >> _fractionalBits;
}

bool operator>(const Fixed& f1, const Fixed& f2)
{
	return f1._raw > f2._raw;
}

bool operator<(const Fixed& f1, const Fixed& f2)
{
	return f1._raw < f2._raw;
}

bool operator>=(const Fixed& f1, const Fixed& f2)
{
	return f1._raw >= f2._raw;
}

bool operator<=(const Fixed& f1, const Fixed& f2)
{
	return f1._raw <= f2._raw;
}

bool operator==(const Fixed& f1, const Fixed& f2)
{
	return f1._raw == f2._raw;
}

bool operator!=(const Fixed& f1, const Fixed& f2)
{
	return f1._raw != f2._raw;
}

std::ostream& operator<<(std::ostream& out, Fixed const& value)
{
    out << value.toFloat();
    return out;
}