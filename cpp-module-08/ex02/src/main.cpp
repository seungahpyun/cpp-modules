/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/11 11:41:23 by spyun         #+#    #+#                 */
/*   Updated: 2025/09/01 11:47:19 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <stack>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;


	std::cout << "\n=== Test: empty stack test ===" << std::endl;
	{
		MutantStack<int> emptyStack;

		std::cout << "Empty stack size: " << emptyStack.size() << std::endl;
		std::cout << "Is empty: " << emptyStack.empty() << std::endl;

		std::cout << "Iterating empty stack: ";
		for (auto it = emptyStack.begin(); it != emptyStack.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << "(nothing)" << std::endl;
	}
}
