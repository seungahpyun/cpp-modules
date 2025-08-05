/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/05 09:23:25 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/05 10:24:41 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*func)(const T &))
{
	if (!array || length == 0 || !func)
	{
		std::cerr << "Error: Invalid arguments passed to iter." << std::endl;
		return;
	}
	
	for (size_t i = 0; i < length; ++i)
	{
		func(array[i]);
	}
}

#endif
