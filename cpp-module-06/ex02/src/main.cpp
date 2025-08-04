/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/04 10:29:37 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/04 10:46:00 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int main()
{
	std::cout << "Identifying..." << std::endl;

	for (int i = 0; i < 10; ++i)
	{
		Base* base = generate();
		std::cout << "Generated type with pointer: ";
		identify(base);
		std::cout << "Generated type with reference: ";
		identify(*base);
		delete base;
	}

	std::cout << "\nEdge case: Identifying nullptr" << std::endl;
	Base* nullBase = nullptr;
	identify(nullBase);
	return 0;
}
