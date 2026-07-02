/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:56:02 by oztozdem          #+#    #+#             */
/*   Updated: 2025/11/27 11:42:29 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(void) {
	try {
		std::cout << "=== int array ===" << std::endl;
		
		Array<int> arr(3);

		arr[0] = 15;
		arr[1] = 30;
		arr[2] = 45;

		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << "arr[" << i << "] = " << arr[i] << std::endl;

		std::cout << std::endl << "=== copy int array ===" << std::endl;
		
		Array<int> copy(arr);
		copy[0] = 42;
		
		std::cout << "arr[0] = " << arr[0] << " (must be 15)" << std::endl;
		std::cout << "copy[0] = " << copy[0] << " (must be 42)" << std::endl;
		std::cout << "copy[1] = " << copy[1] << " (must be 30)" << std::endl;

		std::cout << std::endl << "=== assign int array ===" << std::endl;
		
		Array<int> op;
		op = arr;
		op[1] = 91;

		std::cout << "arr[1] = " << arr[1] << " (must be 30)" << std::endl;
		std::cout << "op[1] = " << op[1] << " (must be 91)" << std::endl;
		std::cout << "op[2] = " << op[2] << " (must be 45)" << std::endl;
		std::cout << op[5] << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		std::cout << std::endl << "=== string ===" << std::endl;
		
		Array<std::string> arr(3);

		arr[0] = "Hello";
		arr[1] = "World";
		arr[2] = "!";

		std::cout << arr[0] << " " << arr[1] << arr[2] << std::endl;

		std::cout << arr[3];
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}