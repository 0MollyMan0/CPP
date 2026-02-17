/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:41:51 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/17 09:48:39 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL));

    std::cout << "=== Creation of the bureaucrats ===" << std::endl;
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);
    Bureaucrat mid("Mid", 70);

    std::cout << std::endl;
    std::cout << "=== Creation of the forms ===" << std::endl;
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << std::endl;
    std::cout << "=== Test 1 : execution without signature ===" << std::endl;
    boss.executeForm(shrub);

    std::cout << std::endl;
    std::cout << "=== Test 2 : signature with a too low grade ===" << std::endl;
    intern.signForm(robot);

    std::cout << std::endl;
    std::cout << "=== Test 3 : signature valid, execution with a too low grade ===" << std::endl;
    boss.signForm(robot);
    intern.executeForm(robot);

    std::cout << std::endl;
    std::cout << "=== Test 4 : execution valid Robotomy (many times) ===" << std::endl;
    for (int i = 0; i < 5; i++)
        boss.executeForm(robot);

    std::cout << std::endl;
    std::cout << "=== Test 5 : Shrubbery ===" << std::endl;
    boss.signForm(shrub);
    boss.executeForm(shrub);

    std::cout << std::endl;
    std::cout << "=== Test 6 : Presidential Pardon ===" << std::endl;
    boss.signForm(pardon);
    boss.executeForm(pardon);

    std::cout << std::endl;
    std::cout << "=== Test 7 : Pure polymorphisme ===" << std::endl;
    AForm* f = new RobotomyRequestForm("HAL 9000");
    boss.signForm(*f);
    boss.executeForm(*f);
    delete f;

    std::cout << std::endl;
    std::cout << "=== END OF TESTS ===" << std::endl;

    return 0;
}
