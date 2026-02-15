/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:26:12 by anfouger          #+#    #+#             */
/*   Updated: 2026/02/15 08:57:05 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Cat.hpp"
#include "./Dog.hpp"
#include "./WrongCat.hpp"
#include <iostream>

int main()
{
	const int number = 4;
	Animal *animals[number];
	for (int i = 0; i < number; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	for (int i = 0; i < number; i++)
		delete animals[i];

	Dog originalDog;
	originalDog.getBrain()->setIdea(0, "I want a bone");

	Dog copyDog(originalDog);
	copyDog.getBrain()->setIdea(0, "I want a nap");

	std::cout << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << copyDog.getBrain()->getIdea(0) << std::endl;

	Cat originalCat;
	originalCat.getBrain()->setIdea(0, "I want a fish");

	Cat copyCat = originalCat;
	copyCat.getBrain()->setIdea(0, "I want a nap");

	std::cout << originalCat.getBrain()->getIdea(0) << std::endl;
	std::cout << copyCat.getBrain()->getIdea(0) << std::endl;
	return (0);
}
