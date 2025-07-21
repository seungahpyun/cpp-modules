/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/21 11:26:42 by spyun         #+#    #+#                 */
/*   Updated: 2025/07/21 14:55:00 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_templates[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
		else
			_templates[i] = nullptr;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		// Delete old templates
		for (int i = 0; i < 4; i++)
		{
			if (_templates[i])
			{
				delete _templates[i];
				_templates[i] = nullptr;
			}
		}

		// Copy new templates
		for (int i = 0; i < 4; i++)
		{
			if (other._templates[i])
				_templates[i] = other._templates[i]->clone();
			else
				_templates[i] = nullptr;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i])
			delete _templates[i];
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
		return;

	for (int i = 0; i < 4; i++)
	{
		if (!_templates[i])
		{
			_templates[i] = materia->clone();
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
		if (_templates[i] && _templates[i]->getType() == type)
		{
			return _templates[i]->clone();
		}
	}
	return 0; // Type not found
}
