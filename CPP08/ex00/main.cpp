/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:35:39 by oztozdem          #+#    #+#             */
/*   Updated: 2025/12/01 12:46:20 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <exception>
#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> v;
	v.push_back(15);
	v.push_back(30);
	v.push_back(45);
	v.push_back(60);

	try {
		std::vector<int>::iterator it = easyfind(v, 30);
		std::cout << "vector: found " << *it << '\n';
		it = easyfind(v, 91);
		std::cout << "vector: found " << *it << '\n';
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::deque<int> dq;
	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);

	try {
		std::deque<int>::iterator it = easyfind(dq, 30);
		std::cout << "deque: found " << *it << '\n';
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}