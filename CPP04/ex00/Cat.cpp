/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:52:23 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/13 12:19:45 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat constructor called\n";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

void Cat::makeSound()
{
	std::cout << "Meow!\n";
}