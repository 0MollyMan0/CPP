/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:26:48 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/17 09:38:59 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137, target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void ShrubberyCreationForm::doAction() const
{
	std::ofstream shrubberyFile((AForm::getTarget() + "_shrubbery").c_str());
	if (!shrubberyFile)
		return ;
	shrubberyFile << "              ,@@@@@@@,\n"
		<< "      ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
		<< "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
		<< "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
		<< "  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
		<< "  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
		<< "  `&%\\ ` /%&'    |.|        \\ '|8'\n"
		<< "      |o|        | |         | |\n"
		<< "      |.|        | |         | |\n"
		<< "   \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
}