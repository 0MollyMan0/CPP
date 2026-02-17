/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:56:21 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/17 11:20:20 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>

class AForm;
class Intern
{
private:
	static AForm* createShrubbery(std::string target);
	static AForm* createRobotomy(std::string target);
	static AForm* createPresidential(std::string target);
public:
	Intern();
	Intern(const Intern& other);
	~Intern();

	Intern& operator=(const Intern& other);

	AForm* makeForm(const std::string name, std::string target);
};


#endif