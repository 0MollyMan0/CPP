/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 21:46:03 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/13 00:49:41 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << RED "ERROR => Not enougth argument to work" RESET << std::endl;
		return (1);
	}
	
	PmergeMe Johnson;

	if (!Johnson.sort(argc, argv))
		return (1);
	return 0;
}
