/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/25 15:51:51 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/26 10:55:23 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <sys/time.h>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	vec_data = other.vec_data;
	deq_data = other.deq_data;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other) {
		vec_data = other.vec_data;
		deq_data = other.deq_data;
	}
	return *this;
}

double PmergeMe::getTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

void PmergeMe::processInput(int argc, char **argv)
{
	if (argc < 2)
	{
		throw std::runtime_error("Error: No arguments provided");
	}

	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];

		if (arg.empty() || (arg[0] == '-') || !std::all_of(arg.begin(), arg.end(), ::isdigit))
		{
			throw std::runtime_error("Error: Invalid argument");
		}

		std::stringstream ss(arg);
		long num;
		ss >> num;

		if (num > INT_MAX || num < 0)
		{
			throw std::runtime_error("Error: Number out of range");
		}

		int value = static_cast<int>(num);
		vec_data.push_back(value);
		deq_data.push_back(value);
	}

	if (vec_data.empty())
	{
		throw std::runtime_error("Error: No valid numbers provided");
	}
}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n)
{
	std::vector<size_t> jacobsthal;
	if (n == 0) return jacobsthal;

	std::vector<size_t> jac_numbers;
	jac_numbers.push_back(0);
	jac_numbers.push_back(1);

	while (jac_numbers.back() < n)
	{
		size_t next = jac_numbers[jac_numbers.size()-1] + 2 * jac_numbers[jac_numbers.size()-2];
		jac_numbers.push_back(next);
	}

	std::vector<bool> used(n + 1, false);

	for (size_t i = 2; i < jac_numbers.size() && jac_numbers[i] <= n; i++)
	{
		size_t jac_num = jac_numbers[i];

		for (size_t j = std::min(jac_num, n); j > jac_numbers[i-1]; j--)
		{
			if (!used[j])
			{
				jacobsthal.push_back(j - 1);
				used[j] = true;
			}
		}
	}

	for (size_t i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			jacobsthal.push_back(i - 1);
		}
	}

	return jacobsthal;
}

void PmergeMe::fordJohnsonVector(std::vector<int>& arr)
{
	if (arr.size() <= 1) return;

	if (arr.size() == 2)
	{
		if (arr[0] > arr[1])
			std::swap(arr[0], arr[1]);
		return;
	}

	std::vector<std::pair<int, int> > pairs;
	bool hasOdd = arr.size() % 2 == 1;
	int oddElement = hasOdd ? arr.back() : 0;

	for (size_t i = 0; i < arr.size() - (hasOdd ? 1 : 0); i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	std::vector<int> largerElements;
	std::vector<int> smallerElements;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		largerElements.push_back(pairs[i].first);
		smallerElements.push_back(pairs[i].second);
	}

	fordJohnsonVector(largerElements);

	std::vector<int> mainChain;
	std::vector<int> pending;

	if (!largerElements.empty())
	{
		mainChain.push_back(smallerElements[0]);
		mainChain.push_back(largerElements[0]);

		for (size_t i = 1; i < largerElements.size(); i++)
		{
			mainChain.push_back(largerElements[i]);
			pending.push_back(smallerElements[i]);
		}
	}

	if (hasOdd)
		pending.push_back(oddElement);

	if (!pending.empty())
	{
		std::vector<size_t> insertOrder = generateJacobsthalSequence(pending.size());

		for (size_t i = 0; i < insertOrder.size(); i++)
		{
			size_t idx = insertOrder[i];
			if (idx < pending.size())
			{
				std::vector<int>::iterator pos = std::lower_bound(
					mainChain.begin(), mainChain.end(), pending[idx]);
				mainChain.insert(pos, pending[idx]);
			}
		}
	}

	arr = mainChain;
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& arr)
{
	if (arr.size() <= 1) return;

	if (arr.size() == 2)
	{
		if (arr[0] > arr[1])
			std::swap(arr[0], arr[1]);
		return;
	}

	std::deque<std::pair<int, int> > pairs;
	bool hasOdd = arr.size() % 2 == 1;
	int oddElement = hasOdd ? arr.back() : 0;

	for (size_t i = 0; i < arr.size() - (hasOdd ? 1 : 0); i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	std::deque<int> largerElements;
	std::deque<int> smallerElements;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		largerElements.push_back(pairs[i].first);
		smallerElements.push_back(pairs[i].second);
	}

	fordJohnsonDeque(largerElements);

	std::deque<int> mainChain;
	std::deque<int> pending;

	if (!largerElements.empty())
	{
		mainChain.push_back(smallerElements[0]);
		mainChain.push_back(largerElements[0]);

		for (size_t i = 1; i < largerElements.size(); i++)
		{
			mainChain.push_back(largerElements[i]);
			pending.push_back(smallerElements[i]);
		}
	}

	if (hasOdd)
		pending.push_back(oddElement);

	if (!pending.empty())
	{
		std::vector<size_t> insertOrder = generateJacobsthalSequence(pending.size());

		for (size_t i = 0; i < insertOrder.size(); i++)
		{
			size_t idx = insertOrder[i];
			if (idx < pending.size())
			{
				std::deque<int>::iterator pos = std::lower_bound(
					mainChain.begin(), mainChain.end(), pending[idx]);
				mainChain.insert(pos, pending[idx]);
			}
		}
	}

	arr = mainChain;
}

void PmergeMe::sortWithVector()
{
	double startTime = getTime();
	fordJohnsonVector(vec_data);
	double endTime = getTime();
	vec_time = endTime - startTime;
}

void PmergeMe::sortWithDeque()
{
	double startTime = getTime();
	fordJohnsonDeque(deq_data);
	double endTime = getTime();
	deq_time = endTime - startTime;
}

void PmergeMe::displayResults(const std::vector<int>& original)
{
	std::cout << "Before: ";
	for (size_t i = 0; i < original.size(); i++)
	{
		if (i > 0) std::cout << " ";
		std::cout << original[i];
		if (i >= 4 && original.size() > 10)
		{
			std::cout << " [...]";
			break;
		}
	}
	std::cout << std::endl;

	std::cout << "After: ";
	for (size_t i = 0; i < vec_data.size(); i++)
	{
		if (i > 0) std::cout << " ";
		std::cout << vec_data[i];
		if (i >= 4 && vec_data.size() > 10)
		{
			std::cout << " [...]";
			break;
		}
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec_data.size()
			  << " elements with std::vector : " << std::fixed << std::setprecision(5)
			  << vec_time << " us" << std::endl;

	std::cout << "Time to process a range of " << deq_data.size()
			  << " elements with std::deque : " << std::fixed << std::setprecision(5)
			  << deq_time << " us" << std::endl;
}

void PmergeMe::run(int argc, char **argv)
{
	try
	{
		processInput(argc, argv);
		std::vector<int> original = vec_data;
		sortWithVector();
		sortWithDeque();
		displayResults(original);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
