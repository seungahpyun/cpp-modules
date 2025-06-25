/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 16:06:52 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/25 09:14:02 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "=== ClapTrap Test ===" << std::endl;

	// Test constructors
	std::cout << "\n--- Creating ClapTraps ---" << std::endl;
	ClapTrap robot1("Hero");
	ClapTrap robot2("Villain");

	// Test basic functionality
	std::cout << "\n--- Basic Actions ---" << std::endl;
	robot1.attack("Villain");
	robot2.takeDamage(0);  // ClapTrap has 0 attack damage
	robot2.beRepaired(3);

	// Test copy constructor
	std::cout << "\n--- Copy Constructor Test ---" << std::endl;
	ClapTrap robot3(robot1);
	robot3.attack("Target");

	// Test assignment operator
	std::cout << "\n--- Assignment Operator Test ---" << std::endl;
	ClapTrap robot4("Temp");
	robot4 = robot2;
	robot4.beRepaired(1);

	// Test edge cases
	std::cout << "\n--- Edge Cases ---" << std::endl;
	robot1.takeDamage(15);  // More damage than HP
	robot1.attack("Ghost");  // Should fail (no HP)

	// Test energy depletion
	std::cout << "\n--- Energy Depletion ---" << std::endl;
	ClapTrap energyTest("EnergyBot");
	for (int i = 0; i < 11; i++) {  // Drain all energy (10) + 1 extra
		energyTest.attack("Dummy");
	}
	energyTest.beRepaired(1);  // Should fail (no energy)

	std::cout << "\n--- End of Tests ---" << std::endl;
	return 0;
}
