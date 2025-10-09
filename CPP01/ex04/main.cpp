/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:14:58 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/01 11:39:59 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

int	main(int argc, char **argv) {	
	if (argc != 4) {
		std::cerr << "Usage: ./Replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	if (std::string(argv[2]).empty()) {
		std::cerr << "Error: s1 cannot be empty." << std::endl;
		return 1;
	}
	
	std::ifstream infile(argv[1]);
	if (!infile.is_open()) {
		std::cerr << "Error: can't open infile." << std::endl;
		return 1;
	}
	
	std::string output = std::string(argv[1]) + ".replace";
	std::ofstream outfile(output.c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error: can't open outfile." << std::endl;
		return 1;
	}
	
	std::ostringstream buffer;
	buffer << infile.rdbuf();
	std::string content = buffer.str();

	std::string result = replace(content, argv[2], argv[3]);
	outfile << result;

	infile.close();
	outfile.close();
	return 0;
}