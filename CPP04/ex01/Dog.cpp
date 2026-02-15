/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:51:50 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/15 11:11:36 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called\n";
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& original) : Animal(original)
{
	std::cout << "Dog copy constructor called\n";
	brain = new Brain(*original.brain);
}

Dog& Dog::operator=(const Dog& original)
{
	if (this != &original) 
	{
		Animal::operator=(original);
		delete brain;
		brain = new Brain(*original.brain);
    }
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
	delete this->brain;
}

Brain *Dog::getBrain()
{
	return this->brain;
}


void Dog::makeSound() const
{
	std::cout << "Bark!\n";
}