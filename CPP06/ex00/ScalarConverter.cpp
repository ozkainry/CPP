/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:28:31 by oztozdem          #+#    #+#             */
/*   Updated: 2025/11/05 14:21:56 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cerrno>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <cctype>
#include <cmath>
#include <climits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
	(void) src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) {
	(void) src;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &input) {
	bool charImpossible = false;
	bool charNonDisplayable = false;
	bool intImpossible = false;
	bool floatImpossible = false;
	char charValue = 0;
	int intValue = 0;
	float floatValue = 0;
	double doubleValue = 0;

	if (input == "nanf" || input == "nan" || input == "+inff"
		|| input == "+inf" || input == "-inff" || input == "-inf") {
		charImpossible = true;
		intImpossible = true;
		if (input == "nanf") {
			floatValue = std::numeric_limits<float>::quiet_NaN();
			doubleValue = static_cast<double>(floatValue);
		}
		else if (input == "nan") {
			doubleValue = std::numeric_limits<double>::quiet_NaN();
			floatValue = static_cast<float>(doubleValue);
		}
		else if (input == "+inff") {
			floatValue = std::numeric_limits<float>::infinity();
			doubleValue = static_cast<double>(floatValue);
		}
		else if (input == "+inf") {
			doubleValue = std::numeric_limits<double>::infinity();
			floatValue = static_cast<float>(doubleValue);
		}
		else if (input == "-inff") {
			floatValue = -std::numeric_limits<float>::infinity();
			doubleValue = static_cast<double>(floatValue);
		}
		else if (input == "-inf") {
			doubleValue = -std::numeric_limits<double>::infinity();
			floatValue = static_cast<float>(doubleValue);
		}
	}
	else if (input.length() == 3 && input[0] == '\'' && input[2] == '\'') {
        charValue = input[1];
        intValue = static_cast<int>(charValue);
        floatValue = static_cast<float>(charValue);
        doubleValue = static_cast<double>(charValue);
    }
	else if (input.length() == 1 && !isdigit(input[0]) && isprint(input[0])) {
		charValue = input[0];
        intValue = static_cast<int>(charValue);
        floatValue = static_cast<float>(charValue);
        doubleValue = static_cast<double>(charValue);
	}
	else {
		errno = 0;
		char* endptr;
		doubleValue = std::strtod(input.c_str(), &endptr);

		if (errno == ERANGE || (*endptr != '\0' && *endptr != 'f')) {
			std::cout	<< "char: impossible" << std::endl
						<< "int: impossible" << std::endl
						<< "float: impossible" << std::endl
						<< "double: impossible" << std::endl;
			return;
		}

		if (doubleValue < std::numeric_limits<int>::min() || doubleValue > std::numeric_limits<int>::max())
			intImpossible = true;
		else
			intValue = static_cast<int>(doubleValue);

		if (doubleValue < 0 || doubleValue > 127)
			charImpossible = true;
		else if (doubleValue < 32 || doubleValue > 126)
			charNonDisplayable = true;
		else
			charValue = static_cast<char>(doubleValue);

		if (doubleValue < -std::numeric_limits<float>::max() || doubleValue > std::numeric_limits<float>::max())
			floatImpossible = true;
		else
			floatValue = static_cast<float>(doubleValue);
	}
	
	if (charImpossible)
		std::cout << "char: impossible" << std::endl;
	else if (charNonDisplayable)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << charValue << "'" << std::endl;

	if (intImpossible)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << intValue << std::endl;

	if (floatImpossible)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;

	std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
}