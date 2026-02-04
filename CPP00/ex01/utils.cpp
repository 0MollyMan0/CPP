/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:11:40 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/04 14:08:17 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	command(void)
{
	std::string input;
	std::getline(std::cin, input);
	if (input == "ADD")
		std::cout << "try to add a new contact\n";
	else if (input == "SEARCH")
		std::cout << "try to search a contact\n";
	else if (input == "EXIT")
		return (0);
	return (1);
}

bool isValidField(const std::string& str)
{
	if (str.empty())
		return (false);
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isspace(str[i]))
            return false;
    }
    return true;
}
