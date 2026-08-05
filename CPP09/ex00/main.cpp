/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:01:50 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/05 12:15:05 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

int main(void)
{
	BitcoinExchange btc;

	btc.loadDatabase("data.csv");
	return 0;
}
