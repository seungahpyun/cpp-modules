/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/11 11:41:23 by spyun         #+#    #+#                 */
/*   Updated: 2025/09/02 09:24:35 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <stack>

int main()
{
	std::cout << "=== Test 1: Basic Push and Pop ===" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << "Top: " << mstack.top() << std::endl;  // Should print 17

		mstack.pop();
		std::cout << "Size after pop: " << mstack.size() << std::endl;  // Should print 1
	}

	std::cout << "\n=== Test 2: Iterator Through Stack ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);

		std::cout << "All elements: ";
		for (auto it = mstack.begin(); it != mstack.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\n=== Test 3: Copy to Normal Stack ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(10);
		mstack.push(20);

		std::stack<int> normalStack(mstack);
		std::cout << "Normal stack top: " << normalStack.top() << std::endl;
		std::cout << "Normal stack size: " << normalStack.size() << std::endl;
	}

	std::cout << "\n=== Test 4: String Type Test ===" << std::endl;
	{
		MutantStack<std::string> strStack;
		strStack.push("Hello");
		strStack.push("World");

		std::cout << "String stack: ";
		for (auto it = strStack.begin(); it != strStack.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\n=== Test 5: Empty Stack ===" << std::endl;
	{
		MutantStack<int> empty;
		std::cout << "Empty size: " << empty.size() << std::endl;
		std::cout << "Is empty: " << empty.empty() << std::endl;

		for (auto it = empty.begin(); it != empty.end(); ++it)
		{
			std::cout << "This shouldn't print" << std::endl;
		}
		std::cout << "Empty stack iteration complete" << std::endl;
	}

	return 0;
}
