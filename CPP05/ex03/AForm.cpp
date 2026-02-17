/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:08:20 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/17 11:23:35 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"
#include "./Bureaucrat.hpp"

AForm::AForm(const std::string name, const int gradeSign, const int gradeExe, std::string target) : name(name), gradeSign(gradeSign), gradeExe(gradeExe), target(target)
{
	isSigned = false;
	if (gradeExe > 150 || gradeSign > 150)
		throw GradeTooLowException();
	if (gradeExe < 1 || gradeSign < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& other) : name(other.name), gradeSign(other.gradeSign), gradeExe(other.gradeExe), isSigned(other.isSigned), target(other.target)
{}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->target = other.target;
		this->isSigned = other.isSigned;
	}
	return *this;
}

std::string AForm::getName() const
{
	return this->name;	
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getGradeSign() const
{
	return this->gradeSign;
}

int AForm::getGradeExe() const
{
	return this->gradeExe;	
}

std::string AForm::getTarget() const
{
	return this->target;
}

void AForm::beSigned(Bureaucrat& bur)
{
	if (bur.getGrade() > this->gradeSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw NotSignedException();
	if (executor.getGrade() > this->gradeExe)
		throw GradeTooLowException();
	doAction();
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	std::string itIsSigned;

	if (form.getIsSigned())
		itIsSigned = "is signed";
	else
		itIsSigned = "isn't signed";
	
	out << form.getName()
		<< ", this form required a grade of " << form.getGradeSign()
		<< " to signed it and a grade of " << form.getGradeExe() << " to execute it, "
		<< "the form " << itIsSigned;

	return out;
}
