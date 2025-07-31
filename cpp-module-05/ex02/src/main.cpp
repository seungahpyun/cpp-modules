/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/30 09:00:06 by spyun         #+#    #+#                 */
/*   Updated: 2025/07/31 11:22:33 by seungah       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
    try
    {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;

        AForm* form1 = new PresidentialPardonForm("Alice");
        AForm* form2 = new RobotomyRequestForm("Charlie");
        AForm* form3 = new ShrubberyCreationForm("Garden");

        bob.signForm(*form1);
        bob.signForm(*form2);
        bob.signForm(*form3);

        bob.executeForm(*form1);
        bob.executeForm(*form2);
        bob.executeForm(*form3);

        delete form1;
        delete form2;
        delete form3;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
