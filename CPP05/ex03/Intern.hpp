/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:56:21 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/17 09:58:56 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

class Intern
{
private:
	
public:
	Intern();
	Intern(const Intern& other);
	~Intern();

	Intern& operator=(const Intern* other);
};


#endif