/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:55:36 by oztozdem          #+#    #+#             */
/*   Updated: 2025/11/19 16:01:30 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template<typename T>
void increment(T& val) {
	val++;
}

void to_upper(char& c) {
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

template<typename T>
void print_variable(const T& var) {
	std::cout << var << " ";
}

int main(void) {
	std::cout << "=== Tableau d'entiers ===" << std::endl;
	
	int i[] = {9, 15, 42, 91};
	
	std::cout << "Avant modification: ";
	iter(i, 4, print_variable<int>);
	std::cout << std::endl;
	
	iter(i, 4, increment<int>);

	std::cout << "Apres modification: ";
	iter(i, 4, print_variable<int>);
	std::cout << std::endl;
	
	std::cout << "=== String ===" << std::endl;
	
	char str[] = {"hello"};

	std::cout << "Avant modification: ";
	iter(str, 5, print_variable<char>);
	std::cout << std::endl;
	
	iter(str, 5, to_upper);

	std::cout << "Apres modification: ";
	iter(str, 5, print_variable<char>);
	std::cout << std::endl;
	
	return 0;
}