/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:50:03 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/12 15:27:51 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>
#include <iostream>

Harl::Harl()
{}

Harl::~Harl()
{}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n\n";
}

void	Harl::info()
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!\n\n";
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI've been coming for years, whereas you started working here just last month.\n\n";
}

void	Harl::error()
{
	std::cout << "[ ERROR ]\nThis is unacceptable!\nI want to speak to the manager now.\n\n";
}

void	Harl::complain(std::string level)
{
	int i = 0;
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	// void (Harl::*f[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	while (levels[i] != level && i < 4)
		i++;
	switch (i)
	{
	case 0:
		Harl::debug();
	case 1:
		Harl::info();
	case 2:
		Harl::warning();
	case 3:
		Harl::error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		break;
	}
	// while (levels[i] != level && i <= 4)
	// 	i++;
	// if (i > 4)
	// 	std::cout << "[ Probably complaining about insignificant problems ]\n";
	// while (i <= 4)
	// {
	// 	(this->*f[i])();
	// 	i++;
	// }	
}
