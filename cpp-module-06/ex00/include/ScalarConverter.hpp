/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/01 13:15:45 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/04 09:40:46 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>
#include <limits>

class ScalarConverter
{
	private:
		ScalarConverter() = default;
		ScalarConverter(const ScalarConverter& other) = default;
		ScalarConverter& operator=(const ScalarConverter& other) = default;
		~ScalarConverter() = default;

		static bool isChar(const std::string& input);
		static bool isInt(const std::string& input);
		static bool isFloat(const std::string& input);
		static bool isDouble(const std::string& input);

		static void convertFromChar(const std::string& input);
		static void convertFromInt(const std::string& input);
		static void convertFromFloat(const std::string& input);
		static void convertFromDouble(const std::string& input);
		static void convertFromSpecialFloat(const std::string& input);
		static void convertFromSpecialDouble(const std::string& input);

		static bool isSpecialFloat(const std::string& input);
		static bool isSpecialDouble(const std::string& input);
		static bool isValidDecimal(const std::string& input);
		static void printImpossibleAll();
	public:
		static void convert(const std::string& input);
};

#endif
