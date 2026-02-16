/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:52:53 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/16 09:29:17 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& original) : ClapTrap(original.ClapTrap::_name), ScavTrap(original), FragTrap(original), _name(original._name)
{
	std::cout << "DiamondTrap " << this->_name << " copy constructor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& original)
{
	if (this != &original)
	{
		ClapTrap::operator=(original);
		this->_name = original._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " destructor called\n";
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << "\n";
	std::cout << "ClapTrap name: " << ClapTrap::_name << "\n";
}