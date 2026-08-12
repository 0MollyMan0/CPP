/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 21:47:05 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/13 01:31:09 by anfouger         ###   ########.fr       */
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
# include <cctype>
# include <sys/time.h>

class PmergeMe
{
private:
	// Utils
	void	swapPair(std::pair<int, int> _pair);
	bool	isPositiveInt(const std::string& literal) const;
	int		stringToInt(const std::string& str) const;

	// Vector
	std::vector<int> _vector;
	std::vector<std::pair<int, int> > _vectorPair;
	int		_vectorStraggler;
	bool	addToVector(std::string& literal);
	bool	vectorPart(int nb_input, char **input);
	void	makingVectorPair(bool straggler);

	// Deque
	std::deque<int> _deque;
	bool	addToDeque(std::string& literal);
	bool	dequePart(int nb_input, char **input);
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();
	bool	sort(int nb_input, char **argv);
};


#endif