/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:08:56 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/17 09:20:26 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>

static bool parsing(std::string filename, std::string s1)
{
	if (s1.empty())
		return false;
	std::ifstream infile(filename.c_str());
	if (!infile)
		return false;
	return true;
}

int main(int ac, char **av)
{	
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string line;
	std::string before;
	std::string after;
	size_t pos;
	
	if ( ac != 4 || !parsing(filename, s1))
		return (1);
	
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile)
		return (1);
	std::ifstream infile(filename.c_str());
	while (std::getline(infile, line))
	{
		pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos
				&& s1 != s2)
		{
			before = line.substr(0, pos);
			after = line.substr(pos + s1.length());
			line = before + s2 + after;
			pos += s2.length();
		}
		outfile << line << "\n"; 
	}
	return 0;
}
