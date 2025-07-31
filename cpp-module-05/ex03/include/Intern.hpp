/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/31 00:00:00 by spyun         #+#    #+#                 */
/*   Updated: 2025/07/31 12:30:02 by seungah       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern
{
    private:
        struct FormCreator
        {
            std::string name;
            AForm* (*creator)(const std::string& target);
        };

        static AForm* createShrubberyCreationForm(const std::string& target);
        static AForm* createRobotomyRequestForm(const std::string& target);
        static AForm* createPresidentialPardonForm(const std::string& target);

    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm* makeForm(const std::string& formName, const std::string& target);

};

#endif
