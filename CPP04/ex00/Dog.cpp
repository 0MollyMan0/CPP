/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:51:50 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/15 11:13:08 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog& original) : Animal(original)
{
	std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& original)
{
	if (this != &original) 
		Animal::operator=(original);
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const
{
	std::cout << "Bark!\n";
}