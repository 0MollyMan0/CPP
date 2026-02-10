/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:14:29 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/10 13:23:37 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	private:
		int _raw;
		static const int _fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		~Fixed();
		
		Fixed& operator=(const Fixed& other);
		
		Fixed& operator+(const Fixed& other);
		Fixed& operator-(const Fixed& other);
		Fixed& operator*(const Fixed& other);
		Fixed& operator/(const Fixed& other);

		Fixed& operator++(void);
		Fixed& operator--(void);
		
		friend bool operator>(const Fixed& f1, const Fixed& f2);
		friend bool operator<(const Fixed& f1, const Fixed& f2);
		friend bool operator<=(const Fixed& f1, const Fixed& f2);
		friend bool operator>=(const Fixed& f1, const Fixed& f2);
		friend bool operator==(const Fixed& f1, const Fixed& f2);
		friend bool operator!=(const Fixed& f1, const Fixed& f2);

		int getRawBits(void) const;
		void setRawBits(int);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, Fixed const& value);

#endif