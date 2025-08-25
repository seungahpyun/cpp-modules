/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/25 15:51:51 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/25 15:58:28 by spyun         ########   odam.nl         */
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

void PmergeMe::fordJohnsonVector(std::vector<int>& arr)
{
	if (arr.size() <= 1)
	{
		return;
	}

	if (arr.size() == 2)
	{
		if (arr[0] > arr[1])
		{
			std::swap(arr[0], arr[1]);
		}
		return;
	}

	// Step 1: Create pairs and sort within pairs
	std::vector<std::pair<int, int> > pairs;
	bool hasOdd = arr.size() % 2 == 1;
	int oddElement = hasOdd ? arr.back() : 0;

	for (size_t i = 0; i < arr.size() - (hasOdd ? 1 : 0); i += 2)
	{
		if (arr[i] > arr[i + 1])
		{
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		}
		else
		{
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
		}
	}

	// Step 2: Recursively sort the larger elements
	std::vector<int> largerElements;
	std::vector<int> smallerElements;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		largerElements.push_back(pairs[i].first);
		smallerElements.push_back(pairs[i].second);
	}

	fordJohnsonVector(largerElements);

	// Step 3: Create main chain and pending elements
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

	// Add odd element to pending if exists
	if (hasOdd)
	{
		pending.push_back(oddElement);
	}

	// Step 4: Insert pending elements using binary search
	for (size_t i = 0; i < pending.size(); i++)
	{
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);
		mainChain.insert(pos, pending[i]);
	}

	arr = mainChain;
}

// Ford-Johnson algorithm for deque
void PmergeMe::fordJohnsonDeque(std::deque<int>& arr)
{
	if (arr.size() <= 1)
	{
		return;
	}

	if (arr.size() == 2)
	{
		if (arr[0] > arr[1])
		{
			std::swap(arr[0], arr[1]);
		}
		return;
	}

	// Step 1: Create pairs and sort within pairs
	std::deque<std::pair<int, int> > pairs;
	bool hasOdd = arr.size() % 2 == 1;
	int oddElement = hasOdd ? arr.back() : 0;

	for (size_t i = 0; i < arr.size() - (hasOdd ? 1 : 0); i += 2)
	{
		if (arr[i] > arr[i + 1])
		{
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		}
		else
		{
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
		}
	}

	// Step 2: Recursively sort the larger elements
	std::deque<int> largerElements;
	std::deque<int> smallerElements;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		largerElements.push_back(pairs[i].first);
		smallerElements.push_back(pairs[i].second);
	}

	fordJohnsonDeque(largerElements);

	// Step 3: Create main chain and pending elements
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

	// Add odd element to pending if exists
	if (hasOdd) {
		pending.push_back(oddElement);
	}

	// Step 4: Insert pending elements using binary search
	for (size_t i = 0; i < pending.size(); i++)
	{
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);
		mainChain.insert(pos, pending[i]);
	}

	arr = mainChain;
}

// Sort using vector
void PmergeMe::sortWithVector()
{
	double startTime = getTime();
	fordJohnsonVector(vec_data);
	double endTime = getTime();
	vec_time = endTime - startTime;
}

// Sort using deque
void PmergeMe::sortWithDeque()
{
	double startTime = getTime();
	fordJohnsonDeque(deq_data);
	double endTime = getTime();
	deq_time = endTime - startTime;
}

// Display results
void PmergeMe::displayResults(const std::vector<int>& original)
{
	// Display before
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

	// Display after
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

	// Display timing information
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
