/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:52:23 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/15 11:11:22 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called\n";
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& original) : Animal(original)
{
	std::cout << "Cat copy constructor called\n";
	brain = new Brain(*original.brain);
}

Cat& Cat::operator=(const Cat& original)
{
	if (this != &original) 
	{
		Animal::operator=(original);
		delete brain;
		brain = new Brain(*original.brain);
    }
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
	delete this->brain;
}
Brain *Cat::getBrain()
{
	return this->brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow!\n";
}