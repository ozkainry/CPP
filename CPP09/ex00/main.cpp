/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:31:39 by oztozdem          #+#    #+#             */
/*   Updated: 2025/12/22 14:18:16 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <exception>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	try {
		BitcoinExchange btc;
		btc.readData("data.csv");
		btc.readInput(argv[1]);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}