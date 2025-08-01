/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/01 13:15:45 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/01 13:22:53 by seungah       ########   odam.nl         */
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

    public:
        static void convert(const std::string& input);
};

#endif