/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/06 14:54:46 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/06 15:01:35 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

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

		void addNumber(int number);
		template <typename InputIterator>
		void addNumbers(InputIterator first, InputIterator last);
		int shortestSpan() const;
		int longestSpan() const;
		unsigned int size() const;
		unsigned int maxSize() const;
		const std::vector<int> &getNumbers() const;
};
