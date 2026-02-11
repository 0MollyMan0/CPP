/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:44:05 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/11 11:49:31 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"

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

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	
}
