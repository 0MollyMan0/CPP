/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:41:51 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/16 14:53:01 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat bob("Bob", 1);
		Bureaucrat bobu("Bobu", 75);
		Bureaucrat boba("Boba", 75);
		Bureaucrat boby("Boby", 150);
		Bureaucrat bily(boby);
		std::cout << bob;
		std::cout << bobu;
		std::cout << boba;
		std::cout << boby;
		std::cout << bily;
		bobu.incrementGrade();
		std::cout << "increment bobu grade\n";
		boba.decrementGrade();
		std::cout << "decrement boba grade\n";
		std::cout << bobu;
		std::cout << boba;
		bobu = boba;
		std::cout << "bobu = boba\n";
		std::cout << bobu;
		std::cout << boba;
		boby.incrementGrade();
		std::cout << "increment boby grade\n";
		std::cout << boby;
		bily.decrementGrade();
		bob.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}	
	return 0;
}
