/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:08:27 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/16 15:44:51 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int gradeSign;
	const int gradeExe;
public:
	Form(const std::string name, const int gradeSign, const int gradeExe);
	Form(const Form& other);
	~Form();

	Form& operator=(const Form& other);

	std::string getName() const;
	bool		getIsSigned() const;
	int			getGradeSign() const;
	int			getGradeExe() const;

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

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif