/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:17:02 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/16 09:15:35 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " constructor called\n";
}

FragTrap::FragTrap(const FragTrap& original) : ClapTrap(original)
{	
	std::cout << "FragTrap " << this->_name << " copy constructor called\n";
}
FragTrap& FragTrap::operator=(const FragTrap& original)
{
	if (this != &original)
		ClapTrap::operator=(original);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destructor called\n";
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " requests a positive high five!\n";
}