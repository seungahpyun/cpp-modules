/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/01 13:16:30 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/04 09:38:48 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <scalar value>" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);

	return 0;
}
