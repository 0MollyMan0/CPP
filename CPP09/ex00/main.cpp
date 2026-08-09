/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:01:50 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/09 14:20:17 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	
	BitcoinExchange btc;

	btc.loadDatabase("data.csv");
	btc.processInput(av[1]);
	return (0);
}
