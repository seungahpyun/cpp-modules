/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/21 11:26:27 by spyun         #+#    #+#                 */
/*   Updated: 2025/07/21 14:28:12 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Default constructor
Character::Character() : name("DefaultCharacter"), held_items(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = nullptr;
}

// Parameterized constructor
Character::Character(std::string const & name) : name(name), held_items(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = nullptr;
}

// Copy constructor
Character::Character(const Character& other) : name(other.name), held_items(other.held_items)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = nullptr;
	}
}

// Assignment operator
Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		name = other.name;
		held_items = other.held_items;

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

// Destructor
Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

// Get character name
std::string const & Character::getName() const
{
	return name;
}

// Equip materia
void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Cannot equip nullptr" << std::endl;
		return;
	}

	if (held_items >= 4)
	{
		std::cout << "Inventory full, cannot equip " << m->getType() << std::endl;
		return;
	}

	// Find first empty slot
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			held_items++;
			std::cout << "Equipped " << m->getType() << " in slot " << i
			          << " (" << held_items << "/4)" << std::endl;
			return;
		}
	}
}

// Unequip materia (does NOT delete it)
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index: " << idx << ". Must be 0-3." <<  std::endl;
		return;
	}

	if (!inventory[idx])
	{
		std::cout << "No materia to unequip at index: " << idx <<  std::endl;
		return;
	}

	std::cout << "Unequipping " << inventory[idx]->getType() << " from slot " << idx << std::endl;

	// Important: Do NOT delete the materia (as per exercise requirement)
	// The caller must handle the unequipped materia
	inventory[idx] = nullptr;
	held_items--;

	std::cout << "Materia unequipped (" << held_items << "/4)" << std::endl;
}

// Use materia at index
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index: " << idx << ". Must be 0-3." << std::endl;
		return;
	}

	if (!inventory[idx])
	{
		std::cout << "No materia to use at index: " << idx << std::endl;
		return;
	}

	inventory[idx]->use(target);
}

// Get materia at specific index (helper for memory management)
AMateria* Character::getMateria(int idx) const
{
	if (idx < 0 || idx >= 4)
		return nullptr;
	return inventory[idx];
}

// Get current held items count
int Character::getHeldItems() const
{
	return held_items;
}

// Check if can equip more items
bool Character::canEquip() const
{
	return held_items < 4;
}

// Print inventory status (for debugging)
void Character::printInventory() const
{
	std::cout << name << "'s inventory (" << held_items << "/4):" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "  Slot " << i << ": ";
		if (inventory[i])
			std::cout << inventory[i]->getType() << std::endl;
		else
			std::cout << "empty" << std::endl;
	}
}
