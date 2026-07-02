/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:29:21 by oztozdem          #+#    #+#             */
/*   Updated: 2026/01/13 21:49:03 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <string>
#include <exception>

class RPN {
	private:
		std::stack<int> _stack;

		void calculate(const std::string& s);
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		void tokenize(const std::string &s);

		class InvalidToken : public std::exception {
			public:
				const char* what() const throw() { return "Error: Invalid character.";}
		};

		class NotEnoughOrTooMuchNumbers : public std::exception {
			public:
				const char* what() const throw() { return "Error: Not enough or too much numbers.";}
		};

		class DivisionByZero : public std::exception {
			public:
				const char* what() const throw() { return "Error: You can't divide by zero.";}
		};

		class StillTooManyNumbersInStack : public std::exception {
			public:
				const char* what() const throw() { return "Error: There's still too many numbers in stack.";}
		};
};