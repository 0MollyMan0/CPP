/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:18:48 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/04 15:48:18 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>

PhoneBook::PhoneBook() 
{
	newIndex = 0;
	numberContacts = 0;
}

void PhoneBook::printContact(int index)
{
	std::cout << contacts[index].getFirstName() << "\n";
	std::cout << contacts[index].getLastName() << "\n";
	std::cout << contacts[index].getNickname() << "\n";
	std::cout << contacts[index].getPhoneNumber() << "\n";
	std::cout << contacts[index].getDarkestSecret() << "\n";
}

void PhoneBook::printAllContact()
{
	int index = 0;
	std::string value;
	
	std::cout << "Index     |First Name|Last name |Nickname  ";
	while (!contacts[index].getFirstName().empty())
	{
		std::cout << index << "         |";
		for (size_t j = 0; j < 3; j++)
		{
			if (j == 0)
				value = contacts[index].getFirstName();
			else if (j == 1)
				value = contacts[index].getLastName();
			else if (j == 2)
				value = contacts[index].getNickname();
			for (size_t i = 0; i < 10; i++)
			{
				if (value[i])
				{
					if (value[10] && i == 9)
						std::cout << ".";
					else
						std::cout << value[i];
				}
				else
					std::cout << " ";
			}
			std::cout << "|";
		}
		index++;	
	}
}

bool PhoneBook::addContact()
{
	std::string input;
	
	if (newIndex == 9)
		newIndex = 0;
	do
	{
		std::cout << "First name: ";
		std::getline(std::cin, input);
		if (isValidField(input))
			break;
		std::cout << "No empty fields are allowed\n";
	} while (!isValidField(input));
	contacts[newIndex].setFirstName(input);

	do
	{
		std::cout << "Last name: ";
		std::getline(std::cin, input);
		if (isValidField(input))
			break;
		std::cout << "No empty fields are allowed\n";
	} while (!isValidField(input));
	contacts[newIndex].setLastName(input);

	do
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, input);
		if (isValidField(input))
			break;
		std::cout << "No empty fields are allowed\n";
	} while (!isValidField(input));
	contacts[newIndex].setNickname(input);

	do
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, input);
		if (isValidField(input))
			break;
		std::cout << "No empty fields are allowed\n";
	} while (!isValidField(input));
	contacts[newIndex].setPhoneNumber(input);

	do
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, input);
		if (isValidField(input))
			break;
		std::cout << "No empty fields are allowed\n";
	} while (!isValidField(input));
	contacts[newIndex].setDarkestSecret(input);

	newIndex++;
	if (numberContacts != 8)
		numberContacts++;
	return (true);
}

void PhoneBook::searchContact()
{
	std::string input;
	
	printAllContact();
	std::cout << "Enter the index of the contact you wanna see: ";
	std::getline(std::cin, input);
	while (!s || input < "0" || input > numberContacts)
	{
		std::cout << "A valid index is an index between " << ;
		std::cout << "Enter the index of the contact you wanna see: ";
		std::getline(std::cin, input);
	}
	
}
