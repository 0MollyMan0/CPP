/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:50:17 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/17 09:28:25 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>

class AForm;

class Bureaucrat
{
private:
	const std::string name;
	int	grade;
public:
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat& other);

	std::string getName() const;
	int getGrade() const;

	void decrementGrade();
	void incrementGrade();
	void signForm(AForm& form);
	void executeForm(AForm const & form) const;

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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bur);

#endif