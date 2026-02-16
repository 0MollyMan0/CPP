/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:08:20 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/16 16:17:10 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form.hpp"
#include "./Bureaucrat.hpp"

Form::Form(const std::string name, const int gradeSign, const int gradeExe) : name(name), gradeSign(gradeSign), gradeExe(gradeExe)
{
	isSigned = false;
	if (gradeExe > 150 || gradeSign > 150)
		throw GradeTooLowException();
	if (gradeExe < 1 || gradeSign < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& other) : name(other.name), gradeSign(other.gradeSign), gradeExe(other.gradeExe), isSigned(other.isSigned)
{}

Form::~Form() {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

std::string Form::getName() const
{
	return this->name;	
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int Form::getGradeSign() const
{
	return this->gradeSign;
}

int Form::getGradeExe() const
{
	return this->gradeExe;	
}

void Form::beSigned(Bureaucrat& bur)
{
	if (bur.getGrade() > this->gradeSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	std::string itIsSigned;

	if (form.getIsSigned())
		itIsSigned = "is signed";
	else
		itIsSigned = "isn't signed";
	
	out << form.getName()
		<< ", form required a grade of " << form.getGradeSign()
		<< " to signed it and a grade of " << form.getGradeExe() << " to execute it, "
		<< "the form " << itIsSigned;

	return out;
}
