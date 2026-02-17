/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:08:27 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/17 09:44:31 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	const int gradeSign;
	const int gradeExe;
	bool isSigned;
	std::string target;
public:
	AForm(const std::string name, const int gradeSign, const int gradeExe, std::string target);
	AForm(const AForm& other);
	virtual ~AForm();

	AForm& operator=(const AForm& other);

	std::string getName() const;
	bool		getIsSigned() const;
	int			getGradeSign() const;
	int			getGradeExe() const;
	std::string	getTarget() const;

	void beSigned(Bureaucrat& bur);
	void execute(Bureaucrat const & executor) const;
	virtual void doAction() const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "grade too high\n";
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "grade too low\n";
			}
	};

	class NotSignedException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "the form isn't signed\n";
			}
	};
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif