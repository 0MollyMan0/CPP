/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:18:39 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/07 09:31:10 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <string>

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		newIndex;
		int 	numberContacts;
		
		void	printContact(int index);
		void	printAllContact();
		int		indexEntry(void);
		
	public:
		PhoneBook();
		bool	addContact();
		bool	searchContact();
};

#endif