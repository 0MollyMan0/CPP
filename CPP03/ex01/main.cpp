/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:13:48 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/13 09:06:36 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"

int main(void)
{
	ClapTrap clap("Didier");
	ScavTrap scav("Michel");
	
	clap.attack("Michel");
	scav.takeDamage(10);
	clap.beRepaired(10);
	scav.takeDamage(20);
	scav.beRepaired(20);
	
	return 0;
}
