/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/21 08:58:26 by spyun         #+#    #+#                 */
/*   Updated: 2025/07/21 10:20:55 by spyun         ########   odam.nl         */
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
	dog.setIdea(0, "Fetch the ball");
	dog.setIdea(1, "Guard the house");
	std::cout << "Dog's idea at index 0: " << dog.getIdea(0) << std::endl;
	std::cout << "Dog's idea at index 1: " << dog.getIdea(1) << std::endl;

	std::cout << "Cat sound: " << std::endl;
	cat->makeSound();
	cat.setIdea(0, "Chase the laser pointer");
	cat.setIdea(1, "Sleep in the sun");
	std::cout << "Cat's idea at index 0: " << cat.getIdea(0) << std::endl;
	std::cout << "Cat's idea at index 1: " << cat.getIdea(1) << std::endl;


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
