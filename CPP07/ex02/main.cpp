/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 02:48:46 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/17 10:01:21 by anfouger         ###   ########.fr       */
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

	std::cout << "\nCorrect access test\n";
	std::cout << numbers[2] << " = numbers[2]" << std::endl;

	numbers[2] = 2;
	std::cout << "\nModification test (numbers[2] = 2;)\n";
	std::cout << numbers[2] << " = numbers[2]" << std::endl;

	std::cout << "\nOff limit access test\n";
	try
	{
		std::cout << numbers[5] << " = numbers[5]" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "not in range of array" << std::endl;
	}

	std::cout << "\nCopy constructor test\n";
	Array<int> numbers_cpy(numbers);
	std::cout << "Array<int>(5) copied." << std::endl;
	std::cout << numbers_cpy[2] << " = numbers_cpy[2]" << std::endl;
	std::cout << numbers_cpy.size() << " = size of numbers_cpy" << std::endl;
	
	std::cout << "\nequal operator test\n";
	numbers = numbers_cpy;
	std::cout << numbers[2] << " = numbers[2]" << std::endl;
	std::cout << numbers.size() << " = size of numbers" << std::endl;

	std::cout << "\n========== String Array ==========\n";	
	Array<std::string> strings(3);
	std::cout << "Array<std::string>(3) created." << std::endl;

	std::cout << "\n========== End of program ==========\n";
	return (0);
}
