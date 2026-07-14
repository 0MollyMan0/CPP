/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 01:14:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/14 02:57:01 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base *generate(void)
{
	switch (rand() % 3)
	{
		case 0: return new A;
		case 1: return new B;
		case 2: return new C;
	}
	return (NULL);
}

void identify(Base* p)
{
	Base	*useless;

	if ((useless = dynamic_cast<A*>(p)))
		std::cout << "A" << std::endl;
	else if ((useless = dynamic_cast<B*>(p)))
		std::cout << "B" << std::endl;
	else if ((useless = dynamic_cast<C*>(p)))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& test = dynamic_cast<A&>(p);
		(void)test;
		std::cout << "A" << std::endl;	
	}
	catch(...)
	{
	}
	try
	{
		B& test = dynamic_cast<B&>(p);
		(void)test;
		std::cout << "B" << std::endl;	
	}
	catch(...)
	{
	}
	try
	{
		C& test = dynamic_cast<C&>(p);
		(void)test;
		std::cout << "C" << std::endl;	
	}
	catch(...)
	{
	}
}

int main(void)
{
	for (size_t i = 0; i < 10; i++)
	{
		Base* obj = generate();

		identify(obj);
		identify(*obj);

		delete obj;
	}
	return (0);
}

