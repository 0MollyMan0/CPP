/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:50:47 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/13 12:16:45 by anfouger         ###   ########.fr       */
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
	virtual ~Animal();
	
	virtual void makeSound(void);
};

#endif