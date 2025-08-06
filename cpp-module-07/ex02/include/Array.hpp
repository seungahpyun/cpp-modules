/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/05 10:20:53 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/06 10:01:57 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T		*_data;
		size_t	_size;

	public:
		Array<T>() : _size(0), _data(nullptr) {};
		Array(size_t n) : _size(n)
		{
			if (n == 0)
				_data = nullptr;
			else
				_data = new T[n]();
		}
		Array(const Array &other);
		~Array<T>()
		{
			if (_data)
				delete[] _data;
		};

		Array &operator=(const Array &other);
		T &operator[](size_t index);
		const T &operator[](size_t index) const;

		size_t getSize() const;
}

#endif
