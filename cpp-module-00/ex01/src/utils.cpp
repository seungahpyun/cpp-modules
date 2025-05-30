/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/25 11:49:25 by spyun         #+#    #+#                 */
/*   Updated: 2025/05/30 14:37:19 by seungah       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool isValidName(const std::string &name)
{
	if (name.empty())
		return false;
	for (size_t i = 0; i < name.length(); i++)
	{
		if (!std::isalpha(name[i]))
			return false;
	}
	return true;
}

bool isValidNumber(const std::string &number)
{
	if (number.empty())
		return false;
	for (size_t i = 0; i < number.length(); i++)
	{
		if (!std::isdigit(number[i]))
			return false;
	}
	return true;
}

std::string getValidInput(const std::string &command, bool (*validator)(const std::string &))
{
	std::string input;
	bool valid = false;

	while (!valid && !std::cin.eof())
	{
		std::cout << command;
		std::getline(std::cin, input);
		
		if (std::cin.eof())
		{
			std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
			exit(1);
		}
		
		if (validator(input))
			valid = true;
		else
			std::cout << RED << "Invalid input" << RESET << std::endl;
	}
	return input;
}

std::string toUpper(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		str[i] = std::toupper(str[i]);
	}
	return str;
}