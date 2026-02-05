/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:51:05 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/05 15:00:56 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie* zombieHorde(int n, std::string name)
{
	Zombie* res;
	
	if (n <= 0)
		return NULL;
	res = new Zombie[n];
	for (int i = 0; i < n; i++)
		res[i].set_name(name);
	return res;
}