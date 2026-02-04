/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:18:39 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/04 10:35:15 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>

class PhoneBook
{
private:
	Contact contacts[8];
public:
	PhoneBook();
	void setContactFirstName(std::string value, int index);
    std::string getContactFirstName(int index) const;
	void setContactLastName(std::string value, int index);
    std::string getContactLastName(int index) const;
	void setContactNickname(std::string value, int index);
    std::string getContactNickname(int index) const;
	void setContactPhoneNumber(std::string value, int index);
    std::string getContactPhoneNumber(int index) const;
	void setContactDarkestSecret(std::string value, int index);
    std::string getContactDarkestSecret(int index) const;
};
