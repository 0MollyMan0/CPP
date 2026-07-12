/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:18:21 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/12 15:08:16 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data		data_set;
	uintptr_t	data_set_ptr_serialized;
	Data		*data_set_ptr;

	data_set.v_char = 'c';
	data_set.v_double = 12.8;
	data_set.v_int = 13;
	std::cout << "Data Set value before serializing" << std::endl;
	std::cout << "data_set->v_char = " << data_set.v_char << std::endl;
	std::cout << "data_set->v_double = " << data_set.v_double << std::endl;
	std::cout << "data_set->v_int = " << data_set.v_int << std::endl;
	std::cout << std::endl << "Data Set ptr before serializing" << std::endl;
	std::cout << &data_set << std::endl;
	data_set_ptr_serialized = Serializer::serialize(&data_set);
	std::cout << "Data Set ptr by serialize" << std::endl;
	std::cout << data_set_ptr_serialized << std::endl;
	data_set_ptr = Serializer::deserialize(data_set_ptr_serialized);
	std::cout << std::endl << "Data Set value after serializing" << std::endl;
	std::cout << "data_set->v_char = " << data_set_ptr->v_char << std::endl;
	std::cout << "data_set->v_double = " << data_set_ptr->v_double << std::endl;
	std::cout << "data_set->v_int = " << data_set_ptr->v_int << std::endl;
	if (&data_set == data_set_ptr)
		std::cout << std::endl << "Everything works perfectly" << std::endl;
	return 0;
}
