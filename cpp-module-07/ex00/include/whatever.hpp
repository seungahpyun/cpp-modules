/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/05 09:20:07 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/05 10:15:23 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T &min(const T &a, const T &b)
{
	return (a < b) ? a : b;
}

template <typename T>
const T &max(const T &a, const T &b)
{
	return (a > b) ? a : b;
}

#endif
