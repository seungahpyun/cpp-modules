/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/18 09:26:05 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/18 15:31:07 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]\n"
			  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]\n"
			  << "I cannot believe adding extra bacon costs more money. You don’t put enough! If you did I would not have to ask for it!\n" << std::endl;
}
void	Harl::warning()
{
	std::cout << "[ WARNING ]\n"
			  << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::error()
{
	std::cout << "[ ERROR ]\n"
			  << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(const std::string &level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int levelIndex = -1;

	for (size_t i = 0; i < 4; ++i)
	{
		if (level == levels[i])
		{
			levelIndex = i;
			break;
		}
	}

	switch (levelIndex)
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
