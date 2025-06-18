/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/18 09:09:15 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/18 09:23:25 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	private:
		void debug();
		void info();
		void warning();
		void error();

		static void (Harl::*complaints[4])();
		static const std::string levels[4];
	public:
		Harl();
		~Harl();

		void complain(const std::string &level);
};

#endif
