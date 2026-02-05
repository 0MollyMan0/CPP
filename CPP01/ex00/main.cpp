/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:25:17 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/05 14:46:14 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

int main(void)
{
	randomChump("StackZombie");

	Zombie* z = newZombie("HeapZombie");
	z->announce();
	delete z;

	return 0;
}
