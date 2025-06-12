/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/06 09:36:13 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/12 10:48:36 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie* zombie1 = newZombie("Zombie1");
	zombie1->announce();

	randomChump("Zombie2");

	Zombie* zombie3 = newZombie("Zombie3");
	zombie3->announce();

	delete zombie1;
	delete zombie3;

	return (0);
}
