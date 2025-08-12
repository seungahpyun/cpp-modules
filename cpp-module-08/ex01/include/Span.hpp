/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/06 14:54:46 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/12 07:56:10 by seungah       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

class Span
{
	private:
		std::vector<int>	_numbers;
		unsigned int		_maxSize;
	public:
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		
		template <typename InputIterator>
		void addNumbers(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				if (_numbers.size() >= _maxSize)
				throw std::length_error("Span is full");
				_numbers.push_back(*first);
				++first;
			}
		}
		
		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;
		unsigned int size() const;
		unsigned int maxSize() const;
		const std::vector<int> &getNumbers() const;
};

#endif