/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:11:40 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/05 08:18:45 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.hpp>
#include <PhoneBook.hpp>

static bool isOnlySpace(const std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isspace(str[i]))
			return false;
	}
	return true;
}

bool isValidField(const std::string& str)
{
	if (str.empty() || isOnlySpace(str))
		return false;
    return true;
}

bool isNumber(const std::string& str)
{
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}
