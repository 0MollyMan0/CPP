/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:50:52 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/15 11:12:49 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "Animal constructor called\n";
}

Animal::Animal(const Animal& original) : type(original.type)
{
	std::cout << "Animal copy constructor called\n";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

Animal& Animal::operator=(const Animal& original)
{
	if (this != &original)
		this->type = original.type;
	return *this;
}

std::string Animal::getType(void) const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "* animal sound *\n";
}