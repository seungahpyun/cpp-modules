/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/21 11:26:25 by spyun         #+#    #+#                 */
/*   Updated: 2025/07/21 14:54:31 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"


AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		// Copying type doesn't make sense according to exercise
		// type = other.type;
	}
	return *this;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	// Default implementation - do nothing
}
