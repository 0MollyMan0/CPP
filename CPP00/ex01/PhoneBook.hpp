/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:18:39 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/04 15:41:19 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <string>

class PhoneBook
{
	private:
		Contact contacts[8];
		int	newIndex;
		int numberContacts;
		
		void printContact(int index);
		void printAllContact();
		
	public:
		PhoneBook();
		bool addContact();
		void searchContact();
};

#endif