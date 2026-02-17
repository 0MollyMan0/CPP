/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:25:24 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/17 09:39:10 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
: AForm("PresidentialPardonForm", 25, 5, target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void PresidentialPardonForm::doAction() const
{
	std::cout << AForm::getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}