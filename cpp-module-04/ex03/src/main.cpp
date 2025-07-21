/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/21 11:26:25 by spyun         #+#    #+#                 */
/*   Updated: 2025/07/21 11:59:35 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	std::cout << "=== Exercise 03 Test ===" << std::endl;

	// Required test from exercise
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

	delete bob;
	delete me;
	delete src;

	std::cout << "\n=== Additional Tests ===" << std::endl;

	// Additional comprehensive test
	std::cout << "\n--- Testing character inventory ---" << std::endl;
	IMateriaSource* source = new MateriaSource();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());

	ICharacter* character = new Character("Alice");
	ICharacter* target = new Character("Enemy");

	// Fill inventory
	character->equip(source->createMateria("ice"));
	character->equip(source->createMateria("cure"));
	character->equip(source->createMateria("ice"));
	character->equip(source->createMateria("cure"));

	// Try to equip when full (should automatically delete the extra materia)
	character->equip(source->createMateria("ice"));

	// Use all materias
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Using slot " << i << ": ";
		character->use(i, *target);
	}

	// Test unequip - NOTE: unequipped materias are lost (acceptable for this exercise)
	character->unequip(0);
	character->use(0, *target); // Should do nothing

	// Test invalid indices
	character->use(10, *target); // Should do nothing
	character->unequip(-1); // Should do nothing

	delete target;
	delete character;
	delete source;

	return 0;
}
