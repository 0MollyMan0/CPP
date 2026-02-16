/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:29:18 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/16 19:50:04 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <string>

class RobotomyRequestForm
{
private:
	std::string target;
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
};

#endif