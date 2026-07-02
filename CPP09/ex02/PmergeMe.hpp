/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:46:04 by oztozdem          #+#    #+#             */
/*   Updated: 2026/03/24 14:48:27 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <cstddef>
#include <deque>
#include <iostream>
#include <vector>

class PmergeMe {
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

		void parseArgs(char **argv);
		std::vector<size_t> buildInsertionOrder(size_t size);
		std::vector<size_t> jacobsthalSequence(size_t size);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void sort(char **argv);

		template <typename Container>
		void binaryInsert(Container& c, int value) {
			typename Container::iterator it = std::lower_bound(c.begin(), c.end(), value);
			c.insert(it, value);
		}

		template <typename Container>
		void binaryInsertBounded(Container& c, int value, int bound) {
			typename Container::iterator boundPos = std::lower_bound(c.begin(), c.end(), bound);
			if (boundPos == c.end() || *boundPos != bound) {
				typename Container::iterator it = std::lower_bound(c.begin(), c.end(), value);
				c.insert(it, value);
				return;
			}
			typename Container::iterator it = std::lower_bound(c.begin(), boundPos, value);
			c.insert(it, value);
		}
		
		template <typename Container>
		void makePairs(const Container& input, Container& big, Container& small, Container& bounds, bool& hasOrphan, int& orphan) {
			size_t i = 0;
			for (; i + 1 < input.size(); i += 2) {
				if (input[i] > input[i + 1]) {
					big.push_back(input[i]);
					small.push_back(input[i + 1]);
					bounds.push_back(input[i]);
				}
				else {
					big.push_back(input[i + 1]);
					small.push_back(input[i]);
					bounds.push_back(input[i + 1]);
				}
			}
			
			if (i < input.size()) {
				hasOrphan = true;
				orphan = input[i];
			}
		}

		template <typename Container>
		void fordJohnsonSort(Container &data) {
			if (data.size() <= 1)
				return;

			Container big;
			Container small;
			Container bounds;
			bool hasOrphan = false;
			int orphan = 0;

			makePairs(data, big, small, bounds, hasOrphan, orphan);

			fordJohnsonSort(big);

			std::vector<size_t> order = buildInsertionOrder(small.size());
			for (size_t i = 0; i < order.size(); ++i) {
				size_t idx = order[i];
				int value = small[idx];
				int bound = bounds[idx];
				binaryInsertBounded(big, value, bound);
			}

			if (hasOrphan)
				binaryInsert(big, orphan);
			
			data = big;
		}

		template <typename Container>
		void printContainer(const Container& c) {
			typename Container::const_iterator it = c.begin();
			while (it != c.end()) {
				std::cout << *it;
				++it;
				if (it != c.end())
					std::cout << " ";
			}
			std::cout << std::endl;
		}

		class InvalidArgument : public std::exception {
			public:
				const char* what() const throw() { return "Error: Invalid argument.";}
		};
};