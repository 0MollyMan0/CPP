/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:25:54 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/05 14:51:54 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	~Zombie();
	void set_name(std::string name);
	void announce(void);
};

Zombie* zombieHorde( int N, std::string name );