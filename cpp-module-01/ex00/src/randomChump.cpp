/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/06 09:36:07 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/11 10:22:10 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(const std::string& name)
{
	Zombie zombie(name);
	zombie.announce();
}
