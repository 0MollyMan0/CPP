/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 03:17:38 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/21 05:34:41 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

static void separator(const std::string& title)
{
	std::cout << "\n========== " << title << " ==========\n";
}

int main(void)
{
	srand(time(NULL));

	separator("Subject Test");

	try
	{
		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span  : " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	separator("Overflow");

	try
	{
		Span sp(3);

		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);

		std::cout << "Adding one more..." << std::endl;
		sp.addNumber(4);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	separator("Not enough numbers");

	try
	{
		Span sp(10);

		sp.addNumber(42);

		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	separator("Range using vector");

	try
	{
		std::vector<int> values;

		for (int i = 0; i < 10; i++)
			values.push_back(i * 5);

		Span sp(10);

		sp.addNumbers(values.begin(), values.end());

		std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span  : " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	separator("Range using list");

	try
	{
		std::list<int> values;

		values.push_back(8);
		values.push_back(15);
		values.push_back(42);
		values.push_back(100);
		values.push_back(101);

		Span sp(5);

		sp.addNumbers(values.begin(), values.end());

		std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span  : " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	separator("10000 Numbers");

	try
	{
		Span sp(10000);

		for (int i = 0; i < 10000; i++)
			sp.addNumber(rand());

		std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span  : " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
