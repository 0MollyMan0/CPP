/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:52:23 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/15 11:13:00 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat constructor called\n";
}

Cat::Cat(const Cat& original) : Animal(original)
{
	std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& original)
{
	if (this != &original) 
		Animal::operator=(original);
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow!\n";
}