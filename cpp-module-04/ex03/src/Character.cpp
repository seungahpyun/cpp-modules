/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/21 11:26:27 by spyun         #+#    #+#                 */
/*   Updated: 2025/07/21 12:30:06 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = nullptr;
}

Character::Character(const Character& other) : name(other.name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = nullptr;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		name = other.name;

		// Delete old materias
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
			{
				delete inventory[i];
				inventory[i] = nullptr;
			}
		}

		// Copy new materias
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = nullptr;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;

	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return;
		}
	}
	std::cout << "Inventory full, cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
	{
		delete inventory[idx];
		inventory[idx] = nullptr;
	}
	else if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index: " << idx << ". Cannot unequip." << std::endl;
	}
	else
	{
		std::cout << "No materia to unequip at index: " << idx << std::endl;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
	{
		inventory[idx]->use(target);
	}
	else if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index: " << idx << ". Cannot use." << std::endl;
	}
	else
	{
		std::cout << "No materia to use at index: " << idx << std::endl;
	}
}

