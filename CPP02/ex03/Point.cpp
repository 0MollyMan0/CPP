/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:43:57 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/11 11:42:45 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point& copy) : x(copy.x), y(copy.y){}

Point::~Point()
{
}

Point& Point::operator=(const Point& other)
{
	(void)other;
	return *this;
}

Fixed Point::getX(void) const
{
	return this->x;	
}

Fixed Point::getY(void) const
{
	return this->y;
}