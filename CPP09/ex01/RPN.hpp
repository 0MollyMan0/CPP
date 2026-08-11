/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:31:02 by anfouger          #+#    #+#             */
/*   Updated: 2026/08/11 02:02:19 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stdlib.h>
# include <stack>
# include <string>
# include <iostream>
# include <limits>

# define RESET "\033[0m"
# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"

class RPN
{
private:
	std::stack<int> _stack;
	int		charToFigure(char c) const;
	bool	verifyStack(std::string& input);
	bool	doDiv(void);
	bool	doMult(void);
	bool	doSub(void);
	bool	doAdd(void);
public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	void	calculate(std::string& input);
};

#endif