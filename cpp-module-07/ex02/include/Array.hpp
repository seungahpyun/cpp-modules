/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/05 10:20:53 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/06 14:19:48 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		size_t	_size;
		T*		_data;

	public:
		Array() : _size(0), _data(nullptr) {};

		Array(size_t n) : _size(n)
		{
			if (n == 0)
				_data = nullptr;
			else
				_data = new T[n]();
		}

		Array(const Array &other) : _size(other._size)
		{
			if (_size == 0)
				_data = nullptr;
			else
			{
				_data = new T[_size];
				for (size_t i = 0; i < _size; ++i)
					_data[i] = other._data[i];
			}
		};

		~Array()
		{
			if (_data)
				delete[] _data;
		};

		Array &operator=(const Array &other)
		{
			if (this != &other)
			{
				if (_data)
					delete[] _data;
				_size = other._size;
				if (_size == 0)
					_data = nullptr;
				else
				{
					_data = new T[_size];
					for (size_t i = 0; i < _size; ++i)
						_data[i] = other._data[i];
				}
			}
			return *this;
		};

		T &operator[](size_t index)
		{
			if (index >= _size)
				throw std::out_of_range("Array index out of range");
			return _data[index];
		}

		const T &operator[](size_t index) const
		{
			if (index >= _size)
				throw std::out_of_range("Array index out of range");
			return _data[index];
		};

		size_t size() const { return _size; };
};

#endif
