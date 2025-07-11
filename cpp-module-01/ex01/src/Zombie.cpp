/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/11 10:31:52 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/12 10:09:22 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("")
{
	std::cout << "Default zombie created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " destroyed." << std::endl;
}

void Zombie::announce() const
{
	std::cout << _name << ": Braiiiiiiinnnzzz..." << std::endl;
}

void Zombie::setName(const std::string& name)
{
	_name = name;
	std::cout << "Zombie name set to: " << _name << std::endl;
}
