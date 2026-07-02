/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:29:19 by oztozdem          #+#    #+#             */
/*   Updated: 2026/06/19 15:14:29 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <sstream>

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other)
		_stack = other._stack;
	
	return *this;
}

RPN::~RPN() {}

void RPN::calculate(const std::string &s) {
	if (_stack.size() < 2)
		throw NotEnoughOrTooMuchNumbers();
	
	int b = _stack.top();
	_stack.pop();
	int a = _stack.top();
	_stack.pop();

	if (s == "+")
		_stack.push(a + b);
	else if (s == "-")
		_stack.push(a - b);
	else if (s == "*")
		_stack.push(a * b);
	else if (s == "/") {
		if (b == 0)
			throw DivisionByZero();
		_stack.push(a / b);
	}
}

void RPN::tokenize(const std::string &s) {
	std::stringstream ss(s);
	std::string token;

	while (ss >> token) {
		if (token.size() == 1 && std::isdigit(token[0]))
			_stack.push(std::atoi(token.c_str()));
		else if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (_stack.size() < 2)
				throw NotEnoughOrTooMuchNumbers();
			calculate(token);
		}
		else {
			throw InvalidToken();
		}
	}
	if (_stack.size() > 1)
		throw StillTooManyNumbersInStack();
	std::cout << _stack.top() << std::endl;
}