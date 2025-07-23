/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/21 11:26:27 by spyun         #+#    #+#                 */
/*   Updated: 2025/07/23 14:52:30 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("DefaultCharacter"), _held_items(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(std::string const & name) : _name(name), _held_items(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const Character& other) : _name(other._name), _held_items(other._held_items)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		_held_items = other._held_items;

		// Delete old materias
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = nullptr;
			}
		}

		// Copy new materias
		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = nullptr;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Cannot equip nullptr" << std::endl;
		return;
	}

	if (_held_items >= 4)
	{
		std::cout << "Inventory full, cannot equip " << m->getType() << std::endl;
		return;
	}

	// Find first empty slot
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			_held_items++;
			std::cout << "Equipped " << m->getType() << " in slot " << i
				<< " (" << _held_items << "/4)" << std::endl;
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

	if (!_inventory[idx])
	{
		std::cout << "No materia to unequip at index: " << idx <<  std::endl;
		return;
	}

	std::cout << "Unequipping " << _inventory[idx]->getType() << " from slot " << idx << std::endl;

	// Important: Do NOT delete the materia (as per exercise requirement)
	// The caller must handle the unequipped materia
	_inventory[idx] = nullptr;
	_held_items--;

	std::cout << "Materia unequipped (" << _held_items << "/4)" << std::endl;
}

// Use materia at index
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index: " << idx << ". Must be 0-3." << std::endl;
		return;
	}

	if (!_inventory[idx])
	{
		std::cout << "No materia to use at index: " << idx << std::endl;
		return;
	}

	_inventory[idx]->use(target);
}

AMateria* Character::getMateria(int idx) const
{
	if (idx < 0 || idx >= 4)
		return nullptr;
	return _inventory[idx];
}

int Character::getHeldItems() const
{
	return _held_items;
}

bool Character::canEquip() const
{
	return _held_items < 4;
}

void Character::printInventory() const
{
	std::cout << _name << "'s inventory (" << _held_items << "/4):" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "  Slot " << i << ": ";
		if (_inventory[i])
			std::cout << _inventory[i]->getType() << std::endl;
		else
			std::cout << "empty" << std::endl;
	}
}
