/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:18:48 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/04 14:11:56 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>

PhoneBook::PhoneBook() 
{
	newIndex = 0;
}

bool PhoneBook::addContact()
{
	std::string input;
	
	if (newIndex == 9)
		newIndex = 0;
	std::cout << "First name: ";
	std::getline(std::cin, input);
	if (!isValidField(input))
		return (false);
	contacts[newIndex].setFirstName(input);

	std::cout << "Last name: ";
	std::getline(std::cin, input);
	if (!isValidField(input))
		return (false);
	contacts[newIndex].setLastName(input);

	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	if (!isValidField(input))
		return (false);
	contacts[newIndex].setNickname(input);

	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	if (!isValidField(input))
		return (false);
	contacts[newIndex].setPhoneNumber(input);

	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	if (!isValidField(input))
		return (false);
	contacts[newIndex].setDarkestSecret(input);

	newIndex++;
	return (true);
}

void PhoneBook::printContact(int index)
{
	std::cout << contacts[index].getFirstName() << "\n";
	std::cout << contacts[index].getLastName() << "\n";
	std::cout << contacts[index].getNickname() << "\n";
	std::cout << contacts[index].getPhoneNumber() << "\n";
	std::cout << contacts[index].getDarkestSecret() << "\n";
}
