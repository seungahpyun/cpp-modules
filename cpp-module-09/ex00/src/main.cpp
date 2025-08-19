/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/13 08:55:50 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/19 14:14:38 by seungah       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::map<std::string, double> database;

	if (!loadDatabase("data.csv", database))
	{
		return 1;
	}

	processInputFile(argv[1], database);
	return 0;
}
