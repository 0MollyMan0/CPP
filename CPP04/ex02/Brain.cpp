/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 07:58:13 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/15 08:32:13 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain constructor called\n";
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

void Brain::setIdea(int index, std::string idea)
{
	this->ideas[index] = idea;
}

std::string Brain::getIdea(int index)
{
	return this->ideas[index];
}