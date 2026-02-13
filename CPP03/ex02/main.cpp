/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:13:48 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/13 09:34:19 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

int main(void)
{
	ClapTrap clap("Didier");
	ScavTrap scav("Michel");
	FragTrap frag("Maeva");
	
	clap.attack("Michel");
	scav.takeDamage(10);
	clap.beRepaired(10);
	scav.takeDamage(20);
	scav.beRepaired(20);
	frag.highFivesGuys();
	frag.beRepaired(200);
	
	return 0;
}
