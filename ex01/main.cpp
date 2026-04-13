/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:39:12 by jow               #+#    #+#             */
/*   Updated: 2026/04/13 15:39:14 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data *data = new Data;
	std::cout << "Original address: " << data << std::endl;
	data->message = "Hello";
	std::cout << "Content:" << data->message << std::endl;

	uintptr_t raw = Serializer::serialize(data);
	std::cout << "Address interpreted as integer: " << raw << std::endl;
	Data *new_data = Serializer::deserialize(raw);
	std::cout << "New address: " << new_data << std::endl;
	std::cout << "New content: " << new_data->message << std::endl;
}

/*
 * Key takeaway:
 * 1. data is a pointer that holds the memory address of the object Data
 * 2. inside Data object, exists a string with value "Hello"
 * 3. We use reinterpret_cast to read the memory address of object Data as integers,
 * 		and stores it in type uintptr_t named raw.
 * 4. Then we use reinterpret_cast again to read the integers as memory address and
 * 		pass it to new_data.
 * 5. Both data and new_data points to the same memory address of object Data.
 *
 * The bits never change throughout the process,reinterpret_cast doesn't convert
 * or transform anything,it just changes how the compiler interprets the same bits.
 */
