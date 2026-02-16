/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:53:17 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/16 09:21:12 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "./ScavTrap.hpp"
# include "./FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& original);
	DiamondTrap& operator=(const DiamondTrap& original);
	~DiamondTrap();

	void whoAmI();
	using ScavTrap::attack;
};

#endif