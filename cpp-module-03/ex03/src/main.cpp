/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/25 10:41:58 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/25 10:52:26 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "=== Module 03 Exercise 03: DiamondTrap Test ===" << std::endl;

	std::cout << "\n--- Construction Chaining Test ---" << std::endl;
	DiamondTrap diamond("Hero");

	std::cout << "\n--- Name Identity Test ---" << std::endl;
	diamond.whoAmI();

	std::cout << "\n--- Inherited Functions Test ---" << std::endl;
	diamond.attack("Enemy");           // Should use ScavTrap's attack
	diamond.takeDamage(25);            // From ClapTrap
	diamond.beRepaired(10);            // From ClapTrap

	std::cout << "\n--- Special Abilities Test ---" << std::endl;
	diamond.guardGate();               // From ScavTrap
	diamond.highFivesGuys();           // From FragTrap

	std::cout << "\n--- Attributes Test ---" << std::endl;
	std::cout << "Expected stats:" << std::endl;
	std::cout << "- Hit Points: 100 (from FragTrap)" << std::endl;
	std::cout << "- Energy Points: 50 (from ScavTrap)" << std::endl;
	std::cout << "- Attack Damage: 30 (from FragTrap)" << std::endl;
	std::cout << "- Attack function: from ScavTrap" << std::endl;

	std::cout << "\n--- Copy Constructor Test ---" << std::endl;
	{
		DiamondTrap copy(diamond);
		copy.whoAmI();
	}

	std::cout << "\n--- Assignment Operator Test ---" << std::endl;
	DiamondTrap assigned("Assigned");
	assigned = diamond;
	assigned.whoAmI();

	std::cout << "\n--- Edge Case: Multiple Inheritance Test ---" << std::endl;
	DiamondTrap multi("Multi");

	// Test that we only have one ClapTrap instance
	multi.attack("TestTarget");
	multi.guardGate();
	multi.highFivesGuys();
	multi.whoAmI();

	std::cout << "\n--- Destruction Chaining Test ---" << std::endl;
	// Destructors will be called automatically here
	return 0;
}
