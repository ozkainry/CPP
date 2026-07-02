/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:46:07 by oztozdem          #+#    #+#             */
/*   Updated: 2026/01/13 17:18:26 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error: Must have an argument" << std::endl;
		return 1;
	}

	try {
		PmergeMe merge;
		merge.sort(argv);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}