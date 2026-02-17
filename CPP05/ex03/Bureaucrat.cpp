/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:50:26 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/17 09:30:49 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->grade = other.grade;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

void Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << '\n';
	}
	
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << '\n';
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat&  bur)
{
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".\n";
	return out;
}