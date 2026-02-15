/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:50:52 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/13 14:38:54 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "Animal constructor called\n";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

std::string Animal::getType(void) const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "* animal sound *\n";
}