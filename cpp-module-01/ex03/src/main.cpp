/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/12 11:41:32 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/12 12:18:18 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	{
		std::cout << "=== HumanA ===" << std::endl;
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		std::cout << "\n=== HumanB ===" << std::endl;
		HumanB jim("Jim");
		jim.attack();

		Weapon club = Weapon("crude spiked club");

		std::cout << "Setting weapon for Jim..." << std::endl;
		
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
