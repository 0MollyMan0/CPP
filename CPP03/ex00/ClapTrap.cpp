/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:14:13 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/16 09:10:55 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
	std::cout << "ClapTrap " << this->_name << " constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& original)
{
	*this = original;
	std::cout << "ClapTrap " << this->_name << " copy constructor called\n";
}
ClapTrap& ClapTrap::operator=(const ClapTrap& original)
{
	if (this != &original)
	{
		this->_name = original._name;
		this->_hitPoints = original._hitPoints;
		this->_energyPoints = original._energyPoints;
		this->_attackDamage = original._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destructor called\n";
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\n";
		this->_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " no longer has energy!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " point of damage!\n";
	this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " repairs itself by " << amount << " hit points!\n" ;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " no longer has energy!\n";
}