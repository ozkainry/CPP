/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:46:02 by oztozdem          #+#    #+#             */
/*   Updated: 2026/03/24 14:58:31 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cctype>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <set>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vector(other._vector), _deque(other._deque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

std::vector<size_t> PmergeMe::jacobsthalSequence(size_t size) {
	std::vector<size_t> seq;
	if (size == 0)
		return seq;

	size_t j_prev = 0;
	size_t j_curr = 1;
	seq.push_back(1);

	while (true) {
		size_t j_next = j_curr + 2 * j_prev;
		j_prev = j_curr;
		j_curr = j_next;
		if (j_curr >= size)
			break;
		seq.push_back(j_curr);
	}

	return seq;
}

std::vector<size_t> PmergeMe::buildInsertionOrder(size_t size) {
	std::vector<size_t> order;
	std::vector<bool> used(size, false);
	std::vector<size_t> jacob = jacobsthalSequence(size);

	for (size_t i = 0; i < jacob.size(); ++i) {
		int start = static_cast<int>(jacob[i]);
		int end;
		if (i == 0)
			end = 1;
		else
			end = static_cast<int>(jacob[i - 1]) + 1;

		for (int k = start; k >= end; --k) {
			size_t idx = static_cast<size_t>(k) - 1;
			if (idx < size && !used[idx]) {
				order.push_back(idx);
				used[idx] = true;
			}
		}
	}

	for (size_t i = 0; i < size; ++i) {
		if (!used[i])
			order.push_back(i);
	}
	return order;
}

void PmergeMe::parseArgs(char **argv) { 
	std::set<int> seen;

	for (int i = 0; argv[i]; ++i) {
		if (argv[i][0] == '\0')
			throw InvalidArgument();
		for (int j = 0; argv[i][j]; ++j) {
			if (!std::isdigit(argv[i][j]))
				throw InvalidArgument();
		}

		char *endptr;
		long value = std::strtol(argv[i], &endptr, 10);
		if (*endptr != '\0')
			throw InvalidArgument();
		if (value > INT_MAX || value < 0)
			throw InvalidArgument();
		
		int intValue = static_cast<int>(value);

		if (seen.find(intValue) != seen.end())
			throw InvalidArgument();

		seen.insert(intValue);
		_vector.push_back(intValue);
		_deque.push_back(intValue);
	}
}

void PmergeMe::sort(char **argv) {
	parseArgs(argv + 1);

	std::cout << "Before	: ";
	printContainer(_vector);
	
	clock_t start = clock();
	fordJohnsonSort(_vector);
	clock_t end = clock();

	std::cout << "After	: ";
	printContainer(_vector);

	double timeVec = (double)(end - start) * 1000000 / CLOCKS_PER_SEC;

	start = clock();
	fordJohnsonSort(_deque);
	end = clock();

	double timeDeq = (double)(end - start) * 1000000 / CLOCKS_PER_SEC;

	std::cout	<< "Time to process a range of " << _vector.size()
				<< " elements with std::vector : " << timeVec << " us" << std::endl;

	std::cout	<< "Time to process a range of " << _deque.size()
				<< " elements with std::deque : " << timeDeq << " us" << std::endl;
}
