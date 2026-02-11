/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:44:05 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/11 12:05:47 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"

static bool is_same(Point const a, Point const b)
{
	if (a.getX() == b.getX() && a.getY() == b.getY())
		return (true);
	else
		return (false);	
}

static Fixed cal_w1(Point const a, Point const b, Point const c, Point const point)
{
	Fixed numerator;
	Fixed denominator;
	Fixed res;
	
	numerator = a.getX()*(c.getY() - a.getY()) + (point.getY() - a.getY()) * (c.getX() - a.getX()) - point.getX() * (c.getY() - a.getY());
	denominator = (b.getY() - a.getY()) * (c.getX() - a.getX()) - (b.getX() - a.getX()) * (c.getY() - a.getY());
	res = numerator / denominator;
	return (res); 
}

static Fixed cal_w2(Point const a, Point const b, Point const c, Point const point, Fixed const w1)
{
	Fixed numerator;
	Fixed denominator;
	Fixed res;
	
	numerator = point.getY() - a.getY() - w1 * (b.getY() - a.getY());
	denominator = c.getY() - a.getY();
	res = numerator / denominator;
	return (res); 
}



bool bsp(Point const a, Point const b, Point const c, Point const point)
{	
	if (is_same(a, point) || is_same(b, point) || is_same(c, point))
		return (false);

	Fixed const w1 = cal_w1(a, b, c, point);
	Fixed const w2 = cal_w2(a, b, c, point, w1);
	if (w1 > 0 && w2 > 0 && (w1 + w2) < 1)
		return (true);
	else
		return (false);
}
