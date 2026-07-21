/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 00:45:13 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/21 02:07:47 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

static void	testing_vector(void)
{
	std::vector<int>			vector_container;
	std::vector<int>::iterator	it_vector;

	vector_container.push_back(3);
	vector_container.push_back(8);
	vector_container.push_back(12);
	vector_container.push_back(42);
	vector_container.push_back(7);

	std::cout << "values of vector container:" << std::endl;
	for (std::vector<int>::iterator it_vector = vector_container.begin();
		it_vector != vector_container.end(); ++it_vector)
	{
		std::cout << *it_vector << std::endl;
	}

	int	searching = 42;
	std::cout << std::endl << "searching for " << searching << std::endl;
	try
	{
		it_vector = easyfind(searching, vector_container);
		std::cout << *it_vector << " found" << std::endl;
	}
	catch(...)
	{
		std::cout << searching << " not found" << std::endl;
	}
	
	searching = 100;
	std::cout << std::endl << "searching for " << searching << std::endl;
	try
	{
		it_vector = easyfind(searching, vector_container);
		std::cout << *it_vector << " found" << std::endl;
	}
	catch(...)
	{
		std::cout << searching << " not found" << std::endl;
	}
}

static void	testing_list(void)
{
	std::list<int>				list_container;
	std::list<int>::iterator	it_list;

	list_container.push_back(3);
	list_container.push_back(8);
	list_container.push_back(12);
	list_container.push_back(42);
	list_container.push_back(7);

	std::cout << "values of list container:" << std::endl;
	for (std::list<int>::iterator it_list = list_container.begin();
		it_list != list_container.end(); ++it_list)
	{
		std::cout << *it_list << std::endl;
	}

	int searching = 42;
	std::cout << std::endl << "searching for " << searching << std::endl;
	try
	{
		it_list = easyfind(searching, list_container);
		std::cout << *it_list << " found" << std::endl;
	}
	catch(...)
	{
		std::cout << searching << " not found" << std::endl;
	}

	searching = 100;
	std::cout << std::endl << "searching for " << searching << std::endl;
	try
	{
		it_list = easyfind(searching, list_container);
		std::cout << *it_list << " found" << std::endl;
	}
	catch(...)
	{
		std::cout << searching << " not found" << std::endl;
	}
}

int main(void)
{
	testing_list();
	std::cout << std::endl;
	testing_vector();
	return (0);
}
