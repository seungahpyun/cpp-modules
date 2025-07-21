/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/21 09:03:30 by spyun         #+#    #+#                 */
/*   Updated: 2025/07/21 14:45:01 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Unknown")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Some generic animal sound!" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}

void Animal::setIdea(int index, const std::string& idea)
{
	(void)index;
	(void)idea;
	std::cout << "Animal doesn't have a brain to store ideas!" << std::endl;
}

std::string Animal::getIdea(int index) const
{
	(void)index;
	std::cout << "Animal doesn't have a brain to get ideas from!" << std::endl;
	return "";
}
