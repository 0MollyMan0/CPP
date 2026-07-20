/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 00:44:50 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/21 01:15:33 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <stdlib.h>

template <typename T>
int	easyfind(int searching, T containers)
{
	int i = 0;
	
	while (searching != containers[i])
		++i;
	if (searching == containers[i])
		return (0);
	else
		return (1);
}

#endif