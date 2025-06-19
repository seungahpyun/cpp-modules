/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/12 11:41:17 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/19 15:46:24 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(const std::string& type);
		~Weapon(void);

		const std::string& getType(void) const;
		void setType(const std::string& newType);
};

#endif
