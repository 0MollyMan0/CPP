/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:47:30 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/05 08:53:14 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact() {}

void Contact::setFirstName(const std::string value)
{
	firstName = value;
}
std::string Contact::getFirstName() const
{
	return firstName;
}

void Contact::setLastName(const std::string value)
{
	lastName = value;
}
std::string Contact::getLastName() const
{
	return lastName;
}

void Contact::setNickname(const std::string value)
{
	nickname = value;
}
std::string Contact::getNickname() const
{
	return nickname;
}

void Contact::setPhoneNumber(const std::string value)
{
	phoneNumber = value;
}
std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}

void Contact::setDarkestSecret(const std::string value)
{
	darkestSecret = value;
}
std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}
