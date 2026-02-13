/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:13:58 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/13 09:10:24 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <string>

class ClapTrap
{
protected:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
public:
	ClapTrap(std::string name);
	virtual ~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};




#endif