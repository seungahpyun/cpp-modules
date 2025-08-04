/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/01 13:15:37 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/04 10:53:06 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cctype>

bool isChar(const std::string& input)
{
	return (input.length() == 3 && input[0] == '\'' && input[2] == '\'');
}

bool isInt(const std::string& input)
{
	if (input.empty())
		return false;

	size_t start = 0;
	if (input[0] == '+' || input[0] == '-')
		start = 1;

	if (start >= input.length())
		return false;

	for (size_t i = start; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]))
			return false;
	}

	try
	{
		long long value = std::stoll(input);
		return (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max());
	}
	catch (const std::out_of_range& e)
	{
		return false;
	}
}

bool isValidDecimal(const std::string& input)
{
	if (input.empty())
		return false;

	bool hasDecimalPoint = false;
	size_t start = 0;

	if (input[0] == '+' || input[0] == '-')
		start = 1;

	if (start >= input.length())
		return false;

	for (size_t i = start; i < input.length(); i++)
	{
		if (input[i] == '.')
		{
			if (hasDecimalPoint)
				return false;
			hasDecimalPoint = true;
		}
		else if (!std::isdigit(input[i]))
		{
			return false;
		}
	}
	return hasDecimalPoint;
}

bool isFloat(const std::string& input)
{
	if (input.empty() || input.back() != 'f')
		return false;

	std::string withoutF = input.substr(0, input.length() - 1);
	return isValidDecimal(withoutF);
}

bool isDouble(const std::string& input)
{
	if (input.empty() || input.back() == 'f')
		return false;

	return isValidDecimal(input);
}

bool isSpecialFloat(const std::string& input)
{
	return (input == "nanf" || input == "+inff" || input == "-inff" || input == "inff");
}

bool isSpecialDouble(const std::string& input)
{
	return (input == "nan" || input == "+inf" || input == "-inf" || input == "inf");
}

void convertFromChar(const std::string& input)
{
	char value = input[1];

	if (std::isprint(value))
		std::cout << "char: '" << value << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void convertFromInt(const std::string& input)
{
	try
	{
		int value = std::stoi(input);

		std::cout << "char: ";
		if (value < 0 || value > 127)
			std::cout << "impossible" << std::endl;
		else if (!std::isprint(static_cast<char>(value)))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
		std::cout << "int: " << value << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void convertFromFloat(const std::string& input)
{
	std::string withoutF = input.substr(0, input.length() - 1);
	float value = std::stof(withoutF);

	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value)
		|| value < static_cast<float>(std::numeric_limits<int>::min())
		|| value > static_cast<float>(std::numeric_limits<int>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;

	std::cout << "float: ";
	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1) << value << "f" << std::endl;
	}

	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
	}
}

void convertFromDouble(const std::string& input)
{
	double value = std::stod(input);

	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value)
		|| value < static_cast<double>(std::numeric_limits<int>::min())
		|| value > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;

	std::cout << "float: ";
	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	}

	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
	}
}

void convertFromSpecialFloat(const std::string& input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << input << std::endl;

	std::cout << "double: ";
	if (input == "nanf")
		std::cout << "nan" << std::endl;
	else if (input == "+inff" || input == "inff")
		std::cout << "+inf" << std::endl;
	else if (input == "-inff")
		std::cout << "-inf" << std::endl;
}

void convertFromSpecialDouble(const std::string& input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	std::cout << "float: ";
	if (input == "nan")
		std::cout << "nanf" << std::endl;
	else if (input == "+inf" || input == "inf")
		std::cout << "+inff" << std::endl;
	else if (input == "-inf")
		std::cout << "-inff" << std::endl;

	std::cout << "double: " << input << std::endl;
}

void printImpossibleAll()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
	if (isChar(input))
	{
		convertFromChar(input);
	}
	else if (isSpecialFloat(input))
	{
		convertFromSpecialFloat(input);
	}
	else if (isSpecialDouble(input))
	{
		convertFromSpecialDouble(input);
	}
	else if (isFloat(input))
	{
		convertFromFloat(input);
	}
	else if (isDouble(input))
	{
		convertFromDouble(input);
	}
	else if (isInt(input))
	{
		convertFromInt(input);
	}
	else
	{
		printImpossibleAll();
	}
}
