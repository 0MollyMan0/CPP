/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:49:59 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/04 10:35:31 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
	Contact();
    void setFirstName(std::string value);
    std::string getFirstName() const;
	void setLastName(std::string value);
    std::string getLastName() const;
	void setNickname(std::string value);
    std::string getNickname() const;
	void setPhoneNumber(std::string value);
    std::string getPhoneNumber() const;
	void setDarkestSecret(std::string value);
    std::string getDarkestSecret() const;
};
