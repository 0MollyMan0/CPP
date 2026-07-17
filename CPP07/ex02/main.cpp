/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 02:48:46 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/17 09:05:26 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
	std::cout << "========== Empty Array ==========\n";
	Array<int> empty;
	std::cout << "Empty array created." << std::endl;

	std::cout << "\n========== Int Array ==========\n";
	Array<int> numbers(5);
	std::cout << "Array<int>(5) created." << std::endl;
	std::cout << numbers[2] << "  = numbers[2]" << std::endl;
	numbers[2] = 2;
	std::cout << numbers[2] << "  = numbers[2]" << std::endl;
	try
	{
		std::cout << numbers[5] << " = numbers[5]" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "not in range of array" << std::endl;
	}
	std::cout << "\n========== String Array ==========\n";	
	Array<std::string> strings(3);
	std::cout << "Array<std::string>(3) created." << std::endl;

	std::cout << "\n========== End of program ==========\n";
	return (0);
}
