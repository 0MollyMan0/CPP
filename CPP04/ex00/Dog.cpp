/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:51:50 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/13 12:19:38 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called\n";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

void Dog::makeSound()
{
	std::cout << "Bark!\n";
}