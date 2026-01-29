/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 22:58:32 by jow               #+#    #+#             */
/*   Updated: 2026/01/28 22:58:33 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isValidNumber(const std::string& input)
{
	size_t i = 0;
	bool hasDigit = false;
	int hasDot = 0;

	if (input[i] == '-' || input[i] == '+')
		i++;
	if (i >= input.length())
        return false;
	while (i < input.length() && input[i] != 'f')
	{
		if (isdigit(input[i]))
			hasDigit = true;
		else if (input[i] == '.')
			hasDot++;
		else
			return false;
		i++;
	}
	if (!hasDigit || hasDot > 1)
		return false;
	if (i < input.length() && input[i] == 'f')
    {
        if (i != input.length() - 1)
            return false;
    }
	return true;
}

Type getType(const std::string& input)
{
	if (input.empty())
		return INVALID;
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
		return CHAR;
	if (input.length() == 1 && !isdigit(input[0]))
		return CHAR;
	if (input == "nan" || input == "inf" || input == "+inf" || input == "-inf" || \
		input == "nanf" || input == "+inff" || input == "-inff" || input == "inff")
		return PSEUDO;
	if (input[input.length() - 1] == 'f')
	{
		if (isValidNumber(input))
			return FLOAT;
		else
			return INVALID;
	}
	if (!isValidNumber(input))
		return INVALID;
	if (input.find('.') != std::string::npos)
		return DOUBLE;
	return INT;
}
