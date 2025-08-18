/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/13 08:55:50 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/18 08:58:02 by spyun         ########   odam.nl         */
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

	BitcoinExchange exchange;
	if (!exchange.loadDatabase("data.csv"))
	{
		std::cerr << "Error: could not load database." << std::endl;
		return 1;
	}
	exchange.processInputFile(argv[1]);
	return 0;
}
