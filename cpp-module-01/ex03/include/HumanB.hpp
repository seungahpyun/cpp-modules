/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/12 11:41:24 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/19 15:46:28 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
	private:
		std::string _name;
		Weapon* _weapon;

	public:
		HumanB(const std::string& name);
		~HumanB(void);

		void setWeapon(Weapon& weapon);
		void attack(void) const;
};

#endif
