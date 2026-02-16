/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 08:21:18 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/16 09:19:53 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <string>
# include "./ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& original);
	ScavTrap& operator=(const ScavTrap& original);
	~ScavTrap();

	void attack(const std::string& target);
	void guardGate();
};


#endif