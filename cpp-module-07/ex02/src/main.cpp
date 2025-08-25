/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/05 10:20:51 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/25 15:42:30 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
	try
	{
		std::cout << "=== Testing basic functionality ===" << std::endl;
		Array<int> empty;
		std::cout << "Empty array size: " << empty.size() << std::endl;

		Array<int> intArray(5);
		std::cout << "Int array size: " << intArray.size() << std::endl;

		for (size_t i = 0; i < intArray.size(); ++i)
		{
			intArray[i] = i * 10;
		}

		std::cout << "Array contents: ";
		for (size_t i = 0; i < intArray.size(); ++i)
		{
			std::cout << intArray[i] << " ";
		}

		std::cout << std::endl;
		Array<int> copied(intArray);
		std::cout << "Copied array size: " << copied.size() << std::endl;

		Array<int> assigned;
		assigned = intArray;
		std::cout << "Assigned array size: " << assigned.size() << std::endl;

		std::cout << "Testing out of bounds access..." << std::endl;
		std::cout << intArray[10] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
