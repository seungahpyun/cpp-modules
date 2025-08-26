/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/25 15:51:53 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/26 10:55:31 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <stdexcept>
#include <string>
#include <climits>
#include <cctype>

class PmergeMe
{
	private:
		std::vector<int> vec_data;
		std::deque<int> deq_data;
		double vec_time;
		double deq_time;

		double getTime();

		void fordJohnsonVector(std::vector<int>& arr);
		void fordJohnsonDeque(std::deque<int>& arr);

		std::vector<size_t> generateJacobsthalSequence(size_t n);

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		void processInput(int argc, char **argv);
		void sortWithVector();
		void sortWithDeque();
		void displayResults(const std::vector<int>& original);
		void run(int argc, char **argv);
};

#endif
