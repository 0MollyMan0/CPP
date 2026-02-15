/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:50:47 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/15 10:37:48 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <string>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& original);
		virtual ~Animal();
		
		Animal& operator=(const Animal& original);

		std::string getType(void) const;

		virtual void makeSound(void) const = 0;
};

#endif