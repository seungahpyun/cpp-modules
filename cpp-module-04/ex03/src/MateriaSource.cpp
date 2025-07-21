/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/21 11:26:42 by spyun         #+#    #+#                 */
/*   Updated: 2025/07/21 12:23:01 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		templates[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.templates[i])
			templates[i] = other.templates[i]->clone();
		else
			templates[i] = nullptr;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		// Delete old templates
		for (int i = 0; i < 4; i++)
		{
			if (templates[i])
			{
				delete templates[i];
				templates[i] = nullptr;
			}
		}

		// Copy new templates
		for (int i = 0; i < 4; i++)
		{
			if (other.templates[i])
				templates[i] = other.templates[i]->clone();
			else
				templates[i] = nullptr;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (templates[i])
			delete templates[i];
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
		return;

	for (int i = 0; i < 4; i++)
	{
		if (!templates[i])
		{
			templates[i] = materia->clone();
			delete materia; // Clean up the original
			return;
		}
	}
	delete materia; // If templates are full, clean up
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (templates[i] && templates[i]->getType() == type)
		{
			return templates[i]->clone();
		}
	}
	return 0; // Type not found
}
