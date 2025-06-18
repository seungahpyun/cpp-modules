/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/18 09:09:18 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/18 09:23:23 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug()
{
	std::cout << "[DEBUG]\n"
			  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "[INFO]\n"
			  << "I cannot believe adding extra bacon costs more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}
void	Harl::warning()
{
	std::cout << "[WARNING]\n"
			  << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error()
{
	std::cout << "[ERROR]\n"
			  << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

const std::string Harl::levels[4] =
{
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"
};

void (Harl::*Harl::complaints[4])() =
{
	&Harl::debug,
	&Harl::info,
	&Harl::warning,
	&Harl::error
};

void	Harl::complain(const std::string &level)
{
	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
		{
			(this->*complaints[i])();
			return;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
