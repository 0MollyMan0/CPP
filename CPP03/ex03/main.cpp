/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:13:48 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/13 10:08:47 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamond("diana");
	
	diamond.attack("other");
	diamond.whoAmI();
	
	return 0;
}
