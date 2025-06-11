/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/06 09:36:05 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/11 10:34:59 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << _name << " created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << "destroyed." << std::endl;
}

void Zombie::announce() const
{
	std::cout << _name << ": Braiiiiiiinnnzzz..." << std::endl;
}
