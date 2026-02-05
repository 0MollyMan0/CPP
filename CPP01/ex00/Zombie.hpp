/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:25:54 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/05 14:45:03 by anfouger         ###   ########.fr       */
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

Zombie* newZombie( std::string name );
void randomChump( std::string name );