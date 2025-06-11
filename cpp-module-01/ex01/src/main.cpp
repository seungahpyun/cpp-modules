/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/11 10:31:50 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/11 14:51:36 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 5;
	Zombie* horde = zombieHorde(N, "Zombie");

	if (horde)
	{
		for (int i = 0; i < N; ++i)
		{
			horde[i].announce();
		}
		delete[] horde;
	}
	else
	{
		std::cerr << "Failed to create zombie horde." << std::endl;
	}
	
	horde = nullptr;
	return (0);
}
