/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:13:48 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/13 08:18:26 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

int main(void)
{
	ClapTrap clap1("Didier");
	ClapTrap clap2("Michel");
	
	clap1.attack("Michel");
	clap2.takeDamage(10);
	clap1.beRepaired(10);
	clap1.takeDamage(20);
	clap2.beRepaired(20);
	
	return 0;
}
