/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/21 08:58:26 by spyun         #+#    #+#                 */
/*   Updated: 2025/07/21 09:23:03 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	const WrongAnimal* wrong_animal = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();

	std::cout << "Animal sound: " << std::endl;
	animal->makeSound();

	std::cout << "Dog sound: " << std::endl;
	dog->makeSound();

	std::cout << "Cat sound: " << std::endl;
	cat->makeSound();

	std::cout << "WrongAnimal sound: " << std::endl;
	wrong_animal->makeSound();

	std::cout << "WrongCat sound: " << std::endl;
	wrong_cat->makeSound();


	delete animal;
	delete dog;
	delete cat;
	delete wrong_animal;
	delete wrong_cat;
	
	return 0;
}
