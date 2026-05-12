/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:50:03 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/12 15:15:09 by anfouger         ###   ########.fr       */
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
	std::cout << "[ DEBUG ]\n I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n I really do!\n";
}

void	Harl::info()
{
	std::cout << "[ INFO ]\n I cannot believe adding extra bacon costs more money.\n You didn't put enough bacon in my burger!\n If you did, I wouldn't be asking for more!\n";
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]\n I think I deserve to have some extra bacon for free.\n I've been coming for years, whereas you started working here just last month.\n";
}

void	Harl::error()
{
	std::cout << "[ ERROR ]\n This is unacceptable!\n I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	int i = 0;
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void (Harl::*f[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	while (i < 4)
	{
		if (levels[i] == level)
		{
			(this->*f[i])();
		}
		i++;
	}
}
