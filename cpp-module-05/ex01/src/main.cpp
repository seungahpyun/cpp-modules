/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/28 09:25:27 by spyun         #+#    #+#                 */
/*   Updated: 2025/07/28 11:38:59 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	{
		std::cout << "\n===== Test 3: Form exceptions =====" << std::endl;
		try
		{
			// Form form1("Form1", 50, 100);
			Form form2("Form2", 0, 150);

			// std::cout << form1 << std::endl;
			// std::cout << form2 << std::endl;

			// std::cout << "\nTrying to create Form with too high sign grade..." << std::endl;
			// form1.beSigned(0);

		}
		catch (const Form::GradeTooLowException &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		// catch (std::exception &e)
		// {
		// 	std::cerr << "Unexpected error: " << e.what() << std::endl;
		// }
	}
}
