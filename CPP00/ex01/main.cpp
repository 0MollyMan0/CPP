/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:57:57 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/07 09:31:44 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	int running = 1;
	PhoneBook phoneBook;
	std::string input;
	
	while (running)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (1);
		if (input == "ADD")
		{
			if(!phoneBook.addContact())
				return (1);
		}
		else if (input == "SEARCH")
		{
			if (!phoneBook.searchContact())	
				return (1);
		}
		else if (input == "EXIT")
			running = 0;
	}	
	return (0);
}
