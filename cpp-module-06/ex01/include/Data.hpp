/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/04 10:15:31 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/04 10:24:46 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
	private:
		Data(Data const& src) = default;
		Data& operator=(Data const& others) = default;

	public:
		Data() = default;
		~Data() = default;

		int i;
};

#endif
