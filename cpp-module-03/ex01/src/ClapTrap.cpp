/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 16:06:55 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/23 16:32:19 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hp(10), _ep(10), _ad(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "ClapTrap parameterized constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hp = other._hp;
		_ep = other._ep;
		_ad = other._ad;
	}
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_ep > 0 && _hp > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target
				  << ", causing " << _ad << " points of damage!" << std::endl;
		_ep--;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " cannot attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= _hp)
	{
		_hp = 0;
		std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
	}
	else
	{
		_hp -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount
				  << " points of damage! Remaining HP: " << _hp << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_ep > 0 && _hp > 0)
	{
		_hp += amount;
		_ep--;
		std::cout << "ClapTrap " << _name << " repairs itself for " << amount
				  << " points! Current HP: " << _hp << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " cannot be repaired!" << std::endl;
	}
}
