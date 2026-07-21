/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 00:44:50 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/21 02:08:19 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <stdlib.h>
# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator	easyfind(int searching, T &containers)
{
	typename T::iterator	it = std::find(containers.begin(), containers.end(), searching);
	if (it == containers.end())
		throw std::runtime_error("Not found");
	else
		return (it);
}

#endif