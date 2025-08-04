/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/04 10:29:35 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/04 10:41:29 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

Base* generate(void)
{
	int random = rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		{
			(void)dynamic_cast<A&>(p);
			std::cout << "A" << std::endl;
		}
	}
	catch (const std::bad_cast& e)
	{
		try
		{
			{
				(void)dynamic_cast<B&>(p);
				std::cout << "B" << std::endl;
			}
		}
		catch (const std::bad_cast& e)
		{
			try
			{
				{
					(void)dynamic_cast<C&>(p);
					std::cout << "C" << std::endl;
				}
			}
			catch(const std::bad_cast& e)
			{
				std::cerr << e.what() << std::endl;
			}

		}

	}

}
