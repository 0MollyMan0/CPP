/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:52:29 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/13 14:13:09 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "./Animal.hpp"

class Cat : public Animal
{
private:
	
public:
	Cat();
	~Cat();

	void makeSound(void) const;
};

#endif