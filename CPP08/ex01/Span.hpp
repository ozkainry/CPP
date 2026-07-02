/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:48:18 by oztozdem          #+#    #+#             */
/*   Updated: 2025/12/11 12:14:14 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iterator>
#include <exception>

class Span {
	private:
		unsigned int _n;
		std::vector<int> _v;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int value);
		int shortestSpan();
		int longestSpan();

		template<typename It>
		void addNumbers(It first, It last) {
			typename std::iterator_traits<It>::difference_type dist = std::distance(first, last);
			if (dist <= 0)
				return;
			if (_v.size() + static_cast<std::size_t>(dist) > _n)
				throw FullException();
			_v.insert(_v.end(), first, last);
		};
		
		class FullException : public std::exception {
			public:
				const char* what() const throw() { return "Span is full"; }
		};

		class NotEnoughNumbersException : public std::exception {
			public:
				const char* what() const throw() { return "Not enough numbers to find a span"; }
		};
};