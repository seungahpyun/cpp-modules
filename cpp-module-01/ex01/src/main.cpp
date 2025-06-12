/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/11 10:31:50 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/12 10:26:00 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::cout << "=== Creating zombie horde ===" << std::endl;

	int N = 10;
	Zombie* horde = zombieHorde(N, "Zombie");

	if (horde)
	{
		std::cout << "\n=== Zombies announcing ===" << std::endl;
		for (int i = 0; i < N; ++i)
		{
			horde[i].announce();
		}
		std::cout << "\n=== Destroying horde ===" << std::endl;
		delete[] horde;
		horde = nullptr;
	}
	else
	{
		std::cerr << "Failed to create zombie horde." << std::endl;
		return (1);
	}
	return (0);
}
