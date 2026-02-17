/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:29:12 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/17 09:45:55 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45, target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void RobotomyRequestForm::doAction() const
{
	std::cout << "* drilling noises *" << std::endl;

	if (std::rand() % 2)
		std::cout << AForm::getTarget() << " has been robotomized successfully.\n";
	else
		std::cout << AForm::getTarget() << " has not been robotomized.\n";
}
