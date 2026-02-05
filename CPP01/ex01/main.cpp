/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:25:17 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/05 14:59:54 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int main(void)
{
	int n = 5;
	Zombie* horde = zombieHorde(n, "Bibi");

	for (int i = 0; i < n; i++)
		horde[i].announce();

	delete[] horde;
	return 0;
}
