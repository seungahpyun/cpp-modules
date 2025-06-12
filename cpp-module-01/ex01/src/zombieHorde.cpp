/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/11 10:31:55 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/12 10:13:54 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, const std::string& name)
{
	if (N <= 0)
	{
		std::cerr << "Error: Number of zombies must be positive." << std::endl;
		return (nullptr);
	}

	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
	{
		horde[i].setName(name + " " + std::to_string(i + 1));
	}

	return (horde);
}
