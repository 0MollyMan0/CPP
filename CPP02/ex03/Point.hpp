/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:43:48 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/11 13:49:35 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "./Fixed.hpp"


class Point
{
private:
	Fixed const x;
	Fixed const y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& copy);
	~Point();

	Point& operator=(const Point& other);

	Fixed getX(void) const;
	Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif