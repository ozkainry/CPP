/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:31:45 by oztozdem          #+#    #+#             */
/*   Updated: 2026/06/19 15:38:10 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		_data = other._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::map<std::string, double> BitcoinExchange::readData(const std::string &file) {
	std::string line;
	
	std::ifstream	data_file(file.c_str());
	if (!data_file.is_open())
		throw DataOpenFailed();
	std::getline(data_file, line);
	while (std::getline(data_file, line)) {
		if (line.empty())
			continue;
		
		size_t sep = line.find(',');
		if (sep == std::string::npos)
			continue;

		std::string date = line.substr(0, sep);
		std::string priceStr = line.substr(sep + 1);
		if (priceStr.empty())
			continue;

		double price = std::strtod(priceStr.c_str(), NULL);
		
		_data[date] = price;
	}
	return _data;
}

bool isDigitStr(const std::string &str) {
	for (size_t i = 0; i < str.size(); ++i)
		if (str[i] < '0' || str[i] > '9')
			return false;
	return true;
}

bool BitcoinExchange::isValidDate(const std::string &date) {
	if (date.length() != 10)
		throw InvalidDate();
	if (date[4] != '-' || date[7] != '-')
		throw InvalidDate();

	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	if (!isDigitStr(yearStr) || !isDigitStr(monthStr) || !isDigitStr(dayStr))
		throw InvalidDate();

	int year = std::atoi(yearStr.c_str());
	int month = std::atoi(monthStr.c_str());
	int day = std::atoi(dayStr.c_str());
	
	if (month < 1 || month > 12)
		throw InvalidDate();

	int daysInMonth[12] = {	31, 28, 31, 30,
							31, 30, 31, 31,
							30, 31, 30, 31 };

	bool bissextile = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	if (bissextile)
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1])
		throw InvalidDate();

	return true;
}

bool BitcoinExchange::isValidValue(const std::string &value) {
	if (value.empty())
		throw InvalidValue();

	char *endptr = NULL;
	double n = std::strtod(value.c_str(), &endptr);

	if (!endptr || *endptr != '\0')
		throw InvalidValue();

	if (n < 0)
		throw NegativeValue();
	if (n > 1000)
		throw TooLargeValue();
	
	return true;
}

std::string trim(const std::string &str) {
	size_t start = str.find_first_not_of(" \t");
	if (start == std::string::npos)
		return "";
	
	size_t end = str.find_last_not_of(" \t");
	
	return str.substr(start, end - start + 1);
}

double BitcoinExchange::getRateForDate(const std::string &date) {
	std::map<std::string, double>::iterator it = _data.upper_bound(date);
	
	if (it == _data.begin())
		throw InvalidDate();

	--it;
	return it->second;
}

void BitcoinExchange::readInput(const std::string &file) {
	std::ifstream input(file.c_str());
	if (!input.is_open())
		throw InputOpenFailed();

	std::string line;
	std::getline(input, line);

	while (std::getline(input, line)) {
		if (line.empty())
			continue;
		
		size_t sep = line.find('|');
		if (sep == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, sep));
		std::string valueStr = trim(line.substr(sep + 1));

		try {
			isValidDate(date);
			isValidValue(valueStr);

			double value = std::strtod(valueStr.c_str(), NULL);
			double rate = getRateForDate(date);
			double res = value * rate;

			std::cout << date << " => " << value << " = " << res << std::endl;
		}
		catch (const NegativeValue &e) {
			std::cout << e.what() << std::endl;
		}
		catch (const TooLargeValue &e) {
			std::cout << e.what() << std::endl;
		}
		catch (...) {
			std::cout << "Error: bad input => " << line << std::endl;
		}
	}
}