/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/25 10:41:58 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/25 10:47:21 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << "=== Module 03 Exercise 02 Test ===" << std::endl;

	std::cout << "\n--- ClapTrap Test ---" << std::endl;
	ClapTrap clap("Clappy");
	clap.attack("Enemy");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\n--- ScavTrap Test ---" << std::endl;
	ScavTrap scav("Scavvy");
	scav.attack("Target");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();

	std::cout << "\n--- FragTrap Test ---" << std::endl;
	FragTrap frag("Fraggy");
	frag.attack("Opponent");
	frag.takeDamage(40);
	frag.beRepaired(25);
	frag.highFivesGuys();

	std::cout << "\n--- Construction/Destruction Chaining Test ---" << std::endl;
	{
		std::cout << "Creating FragTrap:" << std::endl;
		FragTrap temp("TempFrag");
		std::cout << "Destroying FragTrap:" << std::endl;
	}

	std::cout << "\n--- Copy Constructor Test ---" << std::endl;
	FragTrap original("Original");
	FragTrap copy(original);
	copy.highFivesGuys();

	std::cout << "\n--- Assignment Operator Test ---" << std::endl;
	FragTrap assigned("Assigned");
	assigned = original;
	assigned.attack("TestTarget");

	std::cout << "\n--- Stats Comparison ---" << std::endl;
	std::cout << "ClapTrap stats: HP=10, EP=10, AD=0" << std::endl;
	std::cout << "ScavTrap stats: HP=100, EP=50, AD=20" << std::endl;
	std::cout << "FragTrap stats: HP=100, EP=100, AD=30" << std::endl;

	std::cout << "\n--- End of Tests ---" << std::endl;
	return 0;
}
