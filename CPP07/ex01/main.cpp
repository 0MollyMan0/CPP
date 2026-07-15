/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:43:03 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/16 01:13:56 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void	increment(T &x)
{
	x++;
}

template <typename T>
void	print(const T &x)
{
	std::cout << x << std::endl;
}

int main()
{
	int tab_int[] = {1, 2, 3};
	double tab_double[] = {1.1, 2.2, 3.3};
	char tab_char[] = {'a', 'b', 'c'};
	const char tab_char_const[] = {'a', 'b', 'c'};

	std::cout << "Original Tab int" << std::endl;
	iter(tab_int, 3, print);
	iter(tab_int, 3, increment);
	std::cout << "Increment Tab int" << std::endl;
	iter(tab_int, 3, print);

	std::cout << std::endl;
	std::cout << "Original Tab double" << std::endl;
	iter(tab_double, 3, print);
	iter(tab_double, 3, increment);
	std::cout << "Increment Tab double" << std::endl;
	iter(tab_double, 3, print);

	std::cout << std::endl;
	std::cout << "Original Tab char" << std::endl;
	iter(tab_char, 3, print);
	iter(tab_char, 3, increment);
	std::cout << "Increment Tab char" << std::endl;
	iter(tab_char, 3, print);

	std::cout << std::endl;
	std::cout << "Original Tab char const" << std::endl;
	iter(tab_char_const, 3, print);
}
