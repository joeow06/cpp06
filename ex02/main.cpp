/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:33:57 by jow               #+#    #+#             */
/*   Updated: 2026/04/13 20:33:57 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base* generate(void)
{
	srand(time(NULL));
	int randomNum = rand() % 3;

	switch (randomNum)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p)) // returns non-null if p is A*
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try // throws std::bad_cast if casting fails
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::exception &e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::exception &e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::exception &e) {}
}

int main()
{
	// Base class pointer -> Derived Class (can be A, B or C)
	Base *obj = generate();

	identify(obj); // pass in pointer
	identify(*obj); // dereferenced

	delete obj;
	return (0);
}

/*
 * Key takeaway:
 * 1. Identify the derived type of an object through
 * 		base class pointer and reference using dynamic_cast (downcasting)
 * 2. Pointer version - use return value to check
 * 3. Reference version - use exception to check
 */
