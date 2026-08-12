/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 21:47:05 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/12 23:28:56 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define RESET "\033[0m"
# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"

# include <stdlib.h>
# include <vector>
# include <deque>
# include <iostream>
# include <string>
# include <sstream>
# include <limits>

class PmergeMe
{
private:
	std::vector<int> _vector;
	std::deque<int> _deque;
	bool	isPositiveInt(const std::string& literal) const;
	bool	addToVectorAndDeque(std::string& literal);
	int		stringToInt(const std::string& str) const;
public:
	PmergeMe();
	PmergeMe(PmergeMe& other);
	PmergeMe& operator=(PmergeMe& other);
	~PmergeMe();
	bool	sort(char **argv);
};


#endif