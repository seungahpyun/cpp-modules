/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/05 09:23:28 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/06 09:40:36 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void printInt(const int &value)
{
	std::cout << value << " ";
}

void printString(const std::string &value)
{
	std::cout << value << " ";
}

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	std::string strArray[] = {"Hello", "World", "Iter", "Template", "Function"};

	std::cout << "Integer array: ";
	iter(intArray, 5, printInt);
	std::cout << std::endl;
	std::cout << "String array: ";
	iter(strArray, 5, printString);
	std::cout << std::endl;

}
