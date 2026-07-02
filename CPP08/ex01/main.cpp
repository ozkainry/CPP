/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:06:33 by oztozdem          #+#    #+#             */
/*   Updated: 2025/12/01 19:42:50 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main(void) {
	Span sp(5);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "sp shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "sp longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		sp.addNumber(64);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	Span small(3);
	
	try {
		small.addNumber(100);
		std::cout << small.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	Span big(100000);
	try {
		std::vector<int> nums;
		nums.reserve(100000);
		for (int i = 0; i < 100000; ++i)
			nums.push_back(i * 2);

		big.addNumbers(nums.begin(), nums.end());

		std::cout << "big shortest span: " << big.shortestSpan() << std::endl;
		std::cout << "big longest span: " << big.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}