/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:30:35 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/11 00:30:40 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	RPN test;
	std::string input = std::string(av[1]);

	if (!test.createStack(input))
		return (1);
	test.printStack();
	return (0);
}
