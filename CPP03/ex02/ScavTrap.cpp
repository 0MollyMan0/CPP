/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 08:21:09 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/16 09:11:45 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& original) : ClapTrap(original)
{	
	std::cout << "ScavTrap " << this->_name << " copy constructor called\n";
}
ScavTrap& ScavTrap::operator=(const ScavTrap& original)
{
	if (this != &original)
		ClapTrap::operator=(original);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destructor called\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\n";
		this->_energyPoints--;
	}
	else
		std::cout << "ScavTrap " << this->_name << " no longer has energy!\n";
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode\n";
}