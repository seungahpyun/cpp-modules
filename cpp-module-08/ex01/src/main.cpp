/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/06 14:54:43 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/26 09:51:24 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
	{
		std::cout << "=== Basic Test ===" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	{
		std::cout << "\n=== Large Scale Test (15,000 numbers) ===" << std::endl;
		try
		{
			Span bigSpan(15000);
			std::vector<int> numbers;
			for (int i = 0; i < 15000; ++i)
			{
				numbers.push_back(i * 2);
			}
			bigSpan.addNumbers(numbers.begin(), numbers.end());
			std::cout << "Size: " << bigSpan.size() << std::endl;
			std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
			std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n=== Exception Test ===" << std::endl;
		try
		{
			Span smallSpan(3);
			std::vector<int> moreNumbers = {1, 2, 3, 4, 5};
			smallSpan.addNumbers(moreNumbers.begin(), moreNumbers.end());
		}
		catch (const std::exception& e)
		{
			std::cout << "Caught expected exception: " << e.what() << std::endl;
		}
	}

	return 0;
}
