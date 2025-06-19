/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/12 11:41:35 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/19 15:47:18 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type) {}
Weapon::~Weapon(void) {}

const std::string& Weapon::getType(void) const
{
	return (_type);
}

void Weapon::setType(const std::string& newType)
{
	_type = newType;
}
