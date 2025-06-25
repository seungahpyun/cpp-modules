/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 16:06:52 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/25 10:31:04 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "=== Constructor Chaining Test ===" << std::endl;
	ScavTrap scav("Guardian");

	std::cout << "\n=== Basic Actions Test ===" << std::endl;
	scav.attack("Enemy");
	scav.takeDamage(30);
	scav.beRepaired(10);

	std::cout << "\n=== Special Ability Test ===" << std::endl;
	scav.guardGate();

	std::cout << "\n=== Destructor Chaining Test ===" << std::endl;
	return 0;
}
