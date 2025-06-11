/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/06 09:36:11 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/11 10:22:19 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(const std::string& name)
{
	Zombie* zombie = new Zombie(name);
	return zombie;
}
