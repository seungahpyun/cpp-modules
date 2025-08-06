/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/06 14:34:32 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/06 14:43:43 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec = {1, 2, 3, 4, 5};

	try
	{
		auto it = easyfind(vec, 3);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		auto it = easyfind(vec, 6);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
