/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:18:48 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/04 10:39:34 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() {}

void PhoneBook::setContactFirstName(const std::string value, int index)
{
	contacts[index].setFirstName(value);
}
std::string PhoneBook::getContactFirstName(int index) const
{
    return contacts[index].getFirstName();
}

void PhoneBook::setContactLastName(const std::string value, int index)
{
	contacts[index].setLastName(value);
}
std::string PhoneBook::getContactLastName(int index) const
{
    return contacts[index].getLastName();
}

void PhoneBook::setContactNickname(const std::string value, int index)
{
	contacts[index].setNickname(value);
}
std::string PhoneBook::getContactNickname(int index) const
{
    return contacts[index].getNickname();
}

void PhoneBook::setContactPhoneNumber(const std::string value, int index)
{
	contacts[index].setPhoneNumber(value);
}
std::string PhoneBook::getContactPhoneNumber(int index) const
{
    return contacts[index].getPhoneNumber();
}

void PhoneBook::setContactDarkestSecret(const std::string value, int index)
{
	contacts[index].setDarkestSecret(value);
}
std::string PhoneBook::getContactDarkestSecret(int index) const
{
    return contacts[index].getDarkestSecret();
}