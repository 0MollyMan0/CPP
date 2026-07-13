/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 01:14:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/14 01:21:56 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Base.hpp>
#include <iostream>

Base *generate(void)
{
	Base	*res;
	int choice = (rand() % 3);

	switch (choice)
	{
	case 0:
		res = new A;
		break;
	
	case 1:
		res = new B;
		break;
	
	case 2:
		res = new C;
		break;
	
	default:
		break;
	}
	return (res);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		cout << "C" << std::endl;
}

void identify(Base& p)
{
	
}

int main(void)
{
	
	return (0);
}

