/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:48:09 by oztozdem          #+#    #+#             */
/*   Updated: 2025/12/03 14:37:06 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <vector>

Span::Span(): _n(0), _v() {}

Span::Span(unsigned int N) : _n(N) {
	_v.reserve(_n);
}

Span::Span(const Span& other) : _n(other._n), _v(other._v) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_n = other._n;
		_v = other._v;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
	if (_v.size() >= _n)
		throw FullException();
	
	_v.push_back(value);
}

int Span::shortestSpan() {
	if (_v.size() < 2)
		throw NotEnoughNumbersException();

	std::vector<int> tmp(_v.begin(), _v.end());
	std::sort(tmp.begin(), tmp.end());

	long long min = std::numeric_limits<long long>::max();

	for (std::size_t i = 1; i < tmp.size(); ++i) {
		long long diff = static_cast<long long>(tmp[i]) - static_cast<long long>(tmp[i - 1]);
		if (diff < min)
			min = diff;
		if (min == 0)
			break;
	}

	return static_cast<int>(min);
}

int Span::longestSpan() {
	if (_v.size() < 2)
		throw NotEnoughNumbersException();
	
	std::vector<int>::iterator min = std::min_element(_v.begin(), _v.end());
	std::vector<int>::iterator max = std::max_element(_v.begin(), _v.end());
	
	long long diff = static_cast<long long>(*max) - static_cast<long long>(*min);
	
	return static_cast<int>(diff);
}
