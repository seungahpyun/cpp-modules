/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/21 08:58:26 by spyun         #+#    #+#                 */
/*   Updated: 2025/07/21 11:05:52 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Basic Test ===" << std::endl;

	Animal* dog = new Dog();
	Animal* cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();

	delete dog;
	delete cat;

	std::cout << "\n=== Deep Copy Test ===" << std::endl;


	Dog original;
	original.setIdea(0, "Original idea");

	Dog copy = original;
	original.setIdea(0, "Modified idea");

	std::cout << "Original: " << original.getIdea(0) << std::endl;
	std::cout << "Copy: " << copy.getIdea(0) << std::endl;

	std::cout << "\n=== Array Test (Main Requirement) ===" << std::endl;

	const int SIZE = 10;
	Animal* animals[SIZE];

	// Half Dog, half Cat
	for (int i = 0; i < SIZE / 2; i++)
		animals[i] = new Dog();
	for (int i = SIZE / 2; i < SIZE; i++)
		animals[i] = new Cat();

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	for (int i = 0; i < SIZE; i++)
		delete animals[i];

	return 0;
}
