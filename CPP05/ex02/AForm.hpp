/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:08:27 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/16 19:23:18 by anfouger         ###   ########.fr       */
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
public:
	AForm(const std::string name, const int gradeSign, const int gradeExe);
	AForm(const AForm& other);
	~AForm();

	AForm& operator=(const AForm& other);

	std::string getName() const;
	bool		getIsSigned() const;
	int			getGradeSign() const;
	int			getGradeExe() const;

	void beSigned(Bureaucrat& bur);

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Grade too high\n";
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Grade too low\n";
			}
	};
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif