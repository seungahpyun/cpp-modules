/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/12 11:41:21 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/12 12:02:45 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
	private:
		std::string _name;
		Weapon& _weapon;

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);

		void attack(void) const;
};

#endif
