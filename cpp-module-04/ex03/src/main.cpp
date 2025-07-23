/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/21 11:26:25 by spyun         #+#    #+#                 */
/*   Updated: 2025/07/23 13:41:11 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
	AMateria* groundMaterias[4];
	int groundCount = 0;

	std::cout << "\n===== Test 1: Learn, Equip, Use =====" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout <<"\n===== Test 2: Inventory Full, Unequip, Unknown =====" << std::endl;

	// Fill inventory
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	// Try to equip when full - safe handling
	tmp = src->createMateria("ice");
	bool inventoryFull = true;
	for (int i = 0; i < 4; ++i)
	{
		if (((Character*)me)->getMateria(i) == nullptr)
		{
			inventoryFull = false;
			break;
		}
	}

	if (!inventoryFull)
	{
		me->equip(tmp);
	}
	else
	{
		std::cout << "Inventory full, storing extra materia on ground" << std::endl;
		if (tmp && groundCount < 4)
			groundMaterias[groundCount++] = tmp;
		else if (groundCount >= 4)
		{
			std::cout << "Ground is full, cannot store more materias!" << std::endl;
			delete tmp;
		}
	}

	// Unequip slot 2 and store on ground
	AMateria* unequipped = ((Character*)me)->getMateria(2);
	me->unequip(2);
	if (unequipped && groundCount < 4)
	{
		std::cout << "Storing unequipped materia on ground" << std::endl;
		groundMaterias[groundCount++] = unequipped;
	}
	else if (groundCount >= 4)
	{
		std::cout << "Ground is full, cannot store more materias!" << std::endl;
		delete unequipped;
	}

	// Refill slot 2
	tmp = src->createMateria("cure");
	me->equip(tmp);

	// Try invalid unequip
	me->unequip(10);

	// Try unknown materia - should return null
	tmp = src->createMateria("fire");
	if (tmp)
	{
		std::cout << "Unexpected: fire materia was created!" << std::endl;
		if (groundCount < 4)
			groundMaterias[groundCount++] = tmp;
		else if (groundCount >= 4)
		{
			std::cout << "Ground is full, cannot store more materias!" << std::endl;
			delete tmp;
		}
	}
	else
	{
		std::cout << "Unknown materia type 'fire' correctly returned null" << std::endl;
	}

	std::cout << "\n===== Test 3: Deep Copy & Assignment =====" << std::endl;
	Character* clone = new Character(*(Character*)me);
	std::cout << "Clone uses slot 0 on bob: ";
	clone->use(0, *bob);
	AMateria* cloneUnequipped = clone->getMateria(0);
	clone->unequip(0);
	if (cloneUnequipped && groundCount < 4)
	{
		std::cout << "Storing clone's unequipped materia on ground" << std::endl;
		groundMaterias[groundCount++] = cloneUnequipped;
	}
	else if (groundCount >= 4)
	{
		std::cout << "Ground is full, cannot store more materias!" << std::endl;
		delete cloneUnequipped;
	}
	std::cout << "Original uses slot 0 on bob: ";
	me->use(0, *bob);
	std::cout << "Clone uses slot 0 on bob (should be empty): ";
	clone->use(0, *bob);

	std::cout <<  "\n===== Test 4: Assignment Operator =====" << std::endl;
	Character assigned;  // Uses default constructor
	assigned = *(Character*)me;
	std::cout << "Assigned uses slot 1 on bob: ";
	assigned.use(1, *bob);

	std::cout << "\n===== Test 5: MateriaSource Copy =====" << std::endl;
	MateriaSource* src2 = new MateriaSource(*(MateriaSource*)src);
	tmp = src2->createMateria("ice");
	bool inventoryFull_assigned = true;
	for (int i = 0; i < 4; ++i)
	{
		if (assigned.getMateria(i) == nullptr)
		{
			inventoryFull_assigned = false;
			break;
		}
	}

	if (!inventoryFull_assigned && tmp)
	{
		std::cout << "src2 creates and equips 'ice' for assigned: ";
		assigned.equip(tmp);
		assigned.use(3, *bob);
	}
	else if (tmp && groundCount < 4)
	{
		std::cout << "Assigned inventory full, storing src2's materia on ground" << std::endl;
		groundMaterias[groundCount++] = tmp;
	}
	else if (groundCount >= 4)
	{
		std::cout << "Ground is full, cannot store more materias!" << std::endl;
		delete tmp;
	}

	delete src2;

	// Test equipping null
	std::cout <<  "\n===== Test 6: Additional Edge Cases =====" << std::endl;
	me->equip(nullptr);
	me->use(-1, *bob);
	me->use(10, *bob);

	// Print final inventory states
	std::cout << "\nFinal inventory states:" << std::endl;
	((Character*)me)->printInventory();
	clone->printInventory();
	assigned.printInventory();

	// Clean up all ground materias
	std::cout << "\n===== Test 7: Memory Cleanup =====" << std::endl;
	std::cout << "Cleaning up " << groundCount << " materias from ground..." << std::endl;
	for (int i = 0; i < groundCount; ++i)
	{
		if (groundMaterias[i])
		{
			std::cout << "Deleting " << groundMaterias[i]->getType() << " materia" << std::endl;
			delete groundMaterias[i];
		}
	}

	delete clone;
	delete bob;
	delete me;
	delete src;

	return 0;
}
