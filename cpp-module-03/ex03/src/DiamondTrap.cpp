/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/25 10:41:55 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/25 10:52:01 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), FragTrap(), ScavTrap(), _name("default")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;

	// Set attributes from different parent classes
	_hitPoints = FragTrap::_hitPoints;      // 100 from FragTrap
	_energyPoints = ScavTrap::_energyPoints; // 50 from ScavTrap
	_attackDamage = FragTrap::_attackDamage; // 30 from FragTrap
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "DiamondTrap parameterized constructor called for " << _name << std::endl;

	// Set attributes from different parent classes
	_hitPoints = FragTrap::_hitPoints;      // 100 from FragTrap
	_energyPoints = ScavTrap::_energyPoints; // 50 from ScavTrap
	_attackDamage = FragTrap::_attackDamage; // 30 from FragTrap
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
