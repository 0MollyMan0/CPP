/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:14:43 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/11 13:52:06 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	this->_raw = 0;
}

Fixed::Fixed(int value)
{
	this->_raw = value << _fractionalBits;
}

Fixed::Fixed(float value)
{
	this->_raw = (int)roundf(value * (1 <<_fractionalBits));
}

Fixed::Fixed(const Fixed& other) 
{
	*this = other;
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed& other)
{
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

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	long tmp = (long)this->_raw * (long)other._raw;
	result.setRawBits(tmp >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	long tmp = ((long)this->_raw << _fractionalBits) / other._raw;
	result.setRawBits(tmp);
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

bool Fixed::operator>(const Fixed& other) const
{
	return this->_raw > other._raw;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->_raw < other._raw;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->_raw >= other._raw;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->_raw <= other._raw;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->_raw == other._raw;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->_raw != other._raw;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

std::ostream& operator<<(std::ostream& out, Fixed const& value)
{
	out << value.toFloat();
	return out;
}