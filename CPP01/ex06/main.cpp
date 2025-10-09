/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:21:52 by oztozdem          #+#    #+#             */
/*   Updated: 2025/08/22 13:57:02 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	getLevelIndex(const std::string& level) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
			return i;
	return -1;
}

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
		return 1;
	}

	Harl harl;
	int	index = getLevelIndex(argv[1]);
	
	switch(index) {
		case 0:
			harl.complain("DEBUG");
			std::cout << std::endl;
			harl.complain("INFO");
			std::cout << std::endl;
			harl.complain("WARNING");
			std::cout << std::endl;
			harl.complain("ERROR");
			break;
		case 1:
			harl.complain("INFO");
			std::cout << std::endl;
			harl.complain("WARNING");
			std::cout << std::endl;
			harl.complain("ERROR");
			break;
		case 2:
			harl.complain("WARNING");
			std::cout << std::endl;
			harl.complain("ERROR");
			break;
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout	<< "[ Probably complaining about insignificant problems ]"
						<< std::endl;
	}
	return 0;
}