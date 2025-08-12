/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/11 11:41:13 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/12 07:56:49 by seungah       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin() { return std::stack<T>::c.begin(); }
	iterator end() { return std::stack<T>::c.end(); }
	const_iterator begin() const { return std::stack<T>::c.begin(); }
	const_iterator end() const { return std::stack<T>::c.end(); }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const MutantStack<T> &ms)
{
	os << "MutantStack contents: ";
	for (typename MutantStack<T>::const_iterator it = ms.begin(); it != ms.end(); ++it)
	{
		os << *it << " ";
	}
	return os;
}

#endif