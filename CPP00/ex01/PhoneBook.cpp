/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:18:48 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/05 09:26:24 by anfouger         ###   ########.fr       */
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
	std::cout << "First name: " << contacts[index].getFirstName() << "\n";
	std::cout << "Last name: " << contacts[index].getLastName() << "\n";
	std::cout << "Nickname: " << contacts[index].getNickname() << "\n";
	std::cout << "Phone number: " << contacts[index].getPhoneNumber() << "\n";
	std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << "\n";
}

void PhoneBook::printAllContact()
{
	std::string value;
	
	std::cout << "Index     |First Name|Last name |Nickname  |\n";
	for (int contactIndex = 0; contactIndex < numberContacts; contactIndex++)
	{
		std::cout << contactIndex << "         |";
		for (int j = 0; j < 3; j++)
		{
			if (j == 0)
				value = contacts[contactIndex].getFirstName();
			else if (j == 1)
				value = contacts[contactIndex].getLastName();
			else if (j == 2)
				value = contacts[contactIndex].getNickname();
			for (size_t charIndex = 0; charIndex < 10; charIndex++)
			{
				if (charIndex < value.length())
				{
					if (value.length() > 10 && charIndex == 9)
						std::cout << ".";
					else
						std::cout << value[charIndex];
				}
				else
					std::cout << " ";
			}
			std::cout << "|";
		}
		std::cout << "\n";
	}
}

int	PhoneBook::indexEntry(void)
{
	std::string input;
	int	index;
	
	while (true)
	{
		std::cout << "\nEnter the index of the contact you wanna see: ";
		std::getline(std::cin, input);

		if (!isNumber(input))
		{
			std::cout << "Invalid index\n";
			continue;
		}
		
		index = stringToInt(input);

		if (index >= 0 && index < numberContacts)
			break;
		std::cout << "Behond limit index\n";
	}
	return (index);
}

bool PhoneBook::addContact()
{
	std::string input;
	
	if (newIndex == 8)
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
	int	index;
	
	printAllContact();
	index = indexEntry();
	printContact(index);
}
