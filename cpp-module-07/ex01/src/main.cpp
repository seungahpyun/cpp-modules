/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/05 09:23:28 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/25 09:12:01 by spyun         ########   odam.nl         */
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

void doubleInt(int &value)
{
	value *= 2;
}

template <typename T>
void printElement(const T &element)
{
	std::cout << element << " ";
}

int main()
{
	std::cout << "=== Basic tests ===" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	std::string strArray[] = {"Hello", "World", "Iter", "Template", "Function"};

	std::cout << "Integer array: ";
	iter(intArray, 5, printInt);
	std::cout << std::endl;

	std::cout << "String array: ";
	iter(strArray, 5, printString);
	std::cout << std::endl;

	std::cout << "\n=== Testing const/non-const support ===" << std::endl;

	const int constArray[] = {10, 20, 30};
	std::cout << "Const array: ";
	iter(constArray, 3, printInt);
	std::cout << std::endl;

	std::cout << "Before doubling: ";
	iter(intArray, 5, printInt);
	std::cout << std::endl;

	iter(intArray, 5, doubleInt);

	std::cout << "After doubling: ";
	iter(intArray, 5, printInt);
	std::cout << std::endl;

	std::cout << "\n=== Testing function template ===" << std::endl;
	std::cout << "Using template function: ";
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl;

	return 0;
}
