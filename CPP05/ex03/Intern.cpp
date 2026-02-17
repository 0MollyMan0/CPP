/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:56:06 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/17 11:38:24 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Intern.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "iostream"

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern::~Intern()
{}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

AForm* Intern::createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	int i = 0;

	std::string formType[3] = { "robotomy request", "shrubbery creation", "presidential pardon"};
	AForm* (*f[3])(std::string) = { &createRobotomy, &createShrubbery, &createPresidential};
	while (i < 3 && formType[i] != name)
		i++;
	if (i < 3)
	{
		AForm *form = (*f[i])(target);
		std::cout << "Intern creates " << *form << "\n";
		return form;	
	}
	std::cout << "test";
	std::cout << "Intern cannot create " << name << ": unknown form name\n";
	return NULL;
}