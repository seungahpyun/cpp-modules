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
#include "Intern.hpp"

int main ()
{
    std::cout << "=== Test 1: Basic functionality with mid-level bureaucrat ===" << std::endl;
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

    std::cout << "\n=== Test 2: High-level bureaucrat (can do everything) ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        std::cout << boss << std::endl;

        AForm* form1 = new PresidentialPardonForm("John");
        AForm* form2 = new RobotomyRequestForm("Jane");
        AForm* form3 = new ShrubberyCreationForm("Park");

        boss.signForm(*form1);
        boss.signForm(*form2);
        boss.signForm(*form3);

        boss.executeForm(*form1);
        boss.executeForm(*form2);
        boss.executeForm(*form3);

        delete form1;
        delete form2;
        delete form3;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Low-level bureaucrat (grade too low) ===" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 150);
        std::cout << intern << std::endl;

        AForm* form1 = new PresidentialPardonForm("Criminal");
        AForm* form2 = new RobotomyRequestForm("Patient");
        AForm* form3 = new ShrubberyCreationForm("Backyard");

        intern.signForm(*form1);
        intern.signForm(*form2);
        intern.signForm(*form3);

        intern.executeForm(*form1);
        intern.executeForm(*form2);
        intern.executeForm(*form3);

        delete form1;
        delete form2;
        delete form3;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Trying to execute unsigned forms ===" << std::endl;
    try
    {
        Bureaucrat boss("SuperBoss", 1);
        
        AForm* form = new PresidentialPardonForm("Unsigned");
        boss.executeForm(*form);
        
        delete form;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Intern makeForm functionality ===" << std::endl;
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            std::cout << *rrf << std::endl;
            delete rrf;
        }
        
        rrf = someRandomIntern.makeForm("shrubbery creation", "Home");
        if (rrf)
        {
            std::cout << *rrf << std::endl;
            delete rrf;
        }
        
        rrf = someRandomIntern.makeForm("presidential pardon", "Ford");
        if (rrf)
        {
            std::cout << *rrf << std::endl;
            delete rrf;
        }
        
        rrf = someRandomIntern.makeForm("invalid form", "Target");
        if (rrf)
        {
            delete rrf;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
