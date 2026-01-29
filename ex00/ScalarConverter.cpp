/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:57:43 by jow               #+#    #+#             */
/*   Updated: 2026/01/26 22:57:44 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cfenv>
#include <iomanip>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void) other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	(void) other;
	return (*this);
}

static void toChar(const std::string& input)
{
	char c;

	if (input.length() == 1)
		c = input[0];
	else
		c = input[1];
	std::cout << "char: ";
	if (isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout <<"int: " << static_cast<int>(c) << std::endl;
	std::cout <<"float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << 'f' << std::endl;
	std::cout <<"double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

static void toInt(const std::string& input)
{
	long num = std::atol(input.c_str());

	std::cout << "char: ";
	if (num < 0 || num > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(num))
			std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;
 }

void ScalarConverter::convert(const std::string& input)
{
	Type myType = getType(input);

	switch (myType)
	{
		case CHAR:
			toChar(input);
			break;
		case INT:
			toInt(input);
			break;
		case FLOAT:
			std::cout << "FLOAT: " << myType << std::endl;
			break;
		case DOUBLE:
			std::cout << "DOUBLE: " << myType << std::endl;
			break;
		case PSEUDO:
			std::cout << "PSEUDO: " << myType << std::endl;
				break;
		case INVALID:
			std::cout << "INVALID: " << myType << std::endl;
			break;
	}
}

/*
 * making convert a Public Static Member function
 * - Belongs to the class, not instances
 * - can be called without an object
 */
