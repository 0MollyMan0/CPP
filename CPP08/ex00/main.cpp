/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 00:45:13 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/21 01:10:14 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <random>
#include <iostream>

int main(void)
{
	int	*array[10];
	int searching = 7;

	for (size_t i = 0; i < 10; i++)
		array[i] = rand();
	std::cout << "values of int array:" << std::endl;
	for ( i = 0; i < count; i++)
		std::cout << array[i] << " ";
	if (!easyfind(searching, array))
		std::cout << std::endl << "rigth int found" << std::endl;
	else
		std::cout << std::endl << "int not found" << std::endl;
	return 0;
}
