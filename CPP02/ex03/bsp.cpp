/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:44:05 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/11 14:08:12 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Point.hpp>

static bool is_same(Point const a, Point const b)
{
	if (a.getX() == b.getX() && a.getY() == b.getY())
		return (true);
	else
		return (false);	
}

static Fixed cal_w1(Point const a, Point const b, Point const c, Point const point)
{
	Fixed numerator  = (b.getY() - c.getY()) * (point.getX() - c.getX()) + (c.getX() - b.getX()) * (point.getY() - c.getY());
	Fixed denominator = (b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY());
	
	if (denominator == Fixed(0))
		throw std::runtime_error("Triangle points are colinear, division by zero avoided");

	return numerator / denominator;
}

static Fixed cal_w2(Point const a, Point const b, Point const c, Point const point)
{
	Fixed numerator  = (c.getY() - a.getY()) * (point.getX() - c.getX()) + (a.getX() - c.getX()) * (point.getY() - c.getY());
	Fixed denominator = (b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY());
	return numerator / denominator;
}


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (is_same(a, point) || is_same(b, point) || is_same(c, point))
		return false;

	Fixed const w1 = cal_w1(a, b, c, point);
	Fixed const w2 = cal_w2(a, b, c, point);
	Fixed const w3 = Fixed(1) - w1 - w2;

	return (w1 > 0 && w2 > 0 && w3 > 0);
}
