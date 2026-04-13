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

static void printFloat(float f)
{
    if (std::isinf(f) || std::isnan(f))
        std::cout << "float: " << f << std::endl;
    else if (f == static_cast<long long>(f)) //check if whole number
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
}

static void printDouble(double d)
{
    if (std::isinf(d) || std::isnan(d))
        std::cout << "double: " << d << std::endl;
    else if (d == static_cast<long long>(d))
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

static void toInt(const std::string& input)
{
	double num = std::strtod(input.c_str(), NULL);

	std::cout << "char: ";
	if (num < 0 || num > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(static_cast<int>(num)))
			std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;
	printFloat(static_cast<float>(num));
	printDouble(num);
 }

static void toFloat(const std::string& input)
{
	float num = std::strtof(input.c_str(), NULL);

	std::cout << "char: ";
	if (num < 0 || num > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(static_cast<int>(num)))
			std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;
	printFloat(num);
	printDouble(static_cast<double>(num));
}

static void toDouble(const std::string& input)
{
	double num = std::strtod(input.c_str(), NULL);

	std::cout << "char: ";
	if (num < 0 || num > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(static_cast<int>(num)))
			std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;
	printFloat(static_cast<float>(num));
	printDouble(num);
}

static void toPseudo(const std::string& input)
{
	if (input == "-inf" || input == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (input == "+inf" || input == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (input == "nan" || input == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
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
			toFloat(input);
			break;
		case DOUBLE:
			toDouble(input);
			break;
		case PSEUDO:
			toPseudo(input);
				break;
		case INVALID:
			std::cout << "Error: conversion is impossible" << std::endl;
			break;
	}
}

/*
 * making convert a Public Static Member function
 * - Belongs to the class, not instances
 * - can be called without an object
 */
