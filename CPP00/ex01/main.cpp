/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:57:57 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/05 08:54:51 by anfouger         ###   ########.fr       */
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
		if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
			phoneBook.searchContact();
		else if (input == "EXIT")
			running = 0;
	}	
	return (0);
}
