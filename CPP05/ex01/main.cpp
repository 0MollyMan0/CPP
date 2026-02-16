/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:41:51 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/16 16:21:00 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat bob("Bob", 1);
		Bureaucrat boby("Boby", 150);
		Form CIA("Top Secret", 1, 1);
		Form Paper("Buy paper", 150, 150);
		bob.signForm(CIA);
		boby.signForm(Paper);
		boby.signForm(CIA);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}	
	return 0;
}
