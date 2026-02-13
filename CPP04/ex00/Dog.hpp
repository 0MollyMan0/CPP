/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:53:27 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/13 14:13:14 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "./Animal.hpp"

class Dog : public Animal
{
private:
	
public:
	Dog();
	~Dog();

	void makeSound(void) const;
};

#endif