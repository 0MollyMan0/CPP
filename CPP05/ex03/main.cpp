/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:41:51 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/17 11:27:11 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

    std::cout << "=== Creating bureaucrats ===" << std::endl;
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);
    Bureaucrat mid("Mid", 70);

    std::cout << "\n=== Creating Intern ===" << std::endl;
    Intern someIntern;

    std::cout << "\n=== Test 1: Valid form creation and execution ===" << std::endl;
    AForm* shrub = someIntern.makeForm("shrubbery creation", "Home");
    AForm* robot = someIntern.makeForm("robotomy request", "Bender");
    AForm* pardon = someIntern.makeForm("presidential pardon", "Arthur Dent");


    boss.signForm(*shrub);
    boss.executeForm(*shrub);

    boss.signForm(*robot);
    boss.executeForm(*robot);

    boss.signForm(*pardon);
    boss.executeForm(*pardon);

    std::cout << "\n=== Test 2: Unknown form name ===" << std::endl;
    AForm* unknown = someIntern.makeForm("magic form", "Target");
    if (!unknown)
        std::cout << "Received NULL as expected for unknown form\n";

    std::cout << "\n=== Test 3: Execution without signature ===" << std::endl;
    AForm* shrub2 = someIntern.makeForm("shrubbery creation", "Garden");
    boss.executeForm(*shrub2);

    std::cout << "\n=== Test 4: Sign with too low grade ===" << std::endl;
    AForm* robot2 = someIntern.makeForm("robotomy request", "HAL");
    intern.signForm(*robot2);

    std::cout << "\n=== Test 5: Execute with too low grade ===" << std::endl;
    boss.signForm(*robot2);
    intern.executeForm(*robot2);

    std::cout << "\n=== Test 6: Robotomy randomness ===" << std::endl;
    
    for (int i = 0; i < 5; i++)
        boss.executeForm(*robot2);

    std::cout << "\n=== Test 7: Polymorphism ===" << std::endl;
    AForm* forms[3];
    forms[0] = someIntern.makeForm("shrubbery creation", "Park");
    forms[1] = someIntern.makeForm("robotomy request", "R2D2");
    forms[2] = someIntern.makeForm("presidential pardon", "Ford Prefect");

    for (int i = 0; i < 3; i++)
    {
        boss.signForm(*forms[i]);
        boss.executeForm(*forms[i]);
    }

    delete shrub;
    delete robot;
    delete pardon;
    delete unknown;
    delete shrub2;
    delete robot2;
    for (int i = 0; i < 3; i++)
        delete forms[i];

    std::cout << "\n=== END OF INTERN TESTS ===" << std::endl;
    return 0;
}

