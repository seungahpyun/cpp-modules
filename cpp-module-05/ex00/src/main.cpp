/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/28 09:25:27 by spyun         #+#    #+#                 */
/*   Updated: 2025/07/28 10:07:13 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << "===== Test 1: Bureaucrat increment =====" << std::endl;
		try
		{
			Bureaucrat a("Alice", 1);
			Bureaucrat b("Bob", 50);
			Bureaucrat c("Charlie", 150);

			std::cout << a << std::endl;
			std::cout << b << std::endl;
			std::cout << c << std::endl;

			std::cout << "\nIncrementing Charlie's grade..." << std::endl;
			c.incrementGrade();
			std::cout << c << std::endl;

			std::cout << "Incrementing Bob's grade..." << std::endl;
			b.incrementGrade();
			std::cout << b << std::endl;

			std::cout << "Incrementing Alice's grade..." << std::endl;
			a.incrementGrade();
			std::cout << a << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n===== Test 2: Bureaucrat decrement =====" << std::endl;
		try
		{
			Bureaucrat a("Alice", 1);
			Bureaucrat b("Bob", 50);
			Bureaucrat c("Charlie", 150);

			std::cout << a << std::endl;
			std::cout << b << std::endl;
			std::cout << c << std::endl;

			std::cout << "\nDecrementing Alice's grade..." << std::endl;
			a.decrementGrade();
			std::cout << a << std::endl;

			std::cout << "Decrementing Bob's grade..." << std::endl;
			b.decrementGrade();
			std::cout << b << std::endl;

			std::cout << "Decrementing Charlie's grade..." << std::endl;
			c.decrementGrade();
			std::cout << c << std::endl;

		}
		catch (const Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}
