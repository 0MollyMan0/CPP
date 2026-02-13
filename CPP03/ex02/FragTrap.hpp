/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:22:33 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/13 09:32:48 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "./ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(const std::string& name);
	~FragTrap();

	void highFivesGuys(void);
};

#endif