/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 16:06:52 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/23 16:32:51 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap claptrap1("ClapTrap1");
	ClapTrap claptrap2("ClapTrap2");

	claptrap1.attack("ClapTrap2");
	claptrap2.takeDamage(0);
	claptrap2.beRepaired(5);

	ClapTrap claptrap3(claptrap1);
	claptrap3.attack("ClapTrap2");

	return 0;
}
