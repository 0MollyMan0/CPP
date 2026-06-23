/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:04:09 by anfouger          #+#    #+#             */
/*   Updated: 2026/06/23 18:23:34 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"

bool	isStringContains(const std::string& str, const int nb, const char contains)
{
	int	count;

	if (nb < 0)
		return (false);
	count = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == contains)
			count++;
	}
	return (count == nb);
}
