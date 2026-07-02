/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:31:42 by oztozdem          #+#    #+#             */
/*   Updated: 2026/01/05 15:46:40 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <map>
#include <string>

class BitcoinExchange {
	private:
		std::map<std::string, double> _data;
		
		double getRateForDate(const std::string &date);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		std::map<std::string, double> readData(const std::string &file);
		void readInput(const std::string &file);
		bool isValidDate(const std::string &date);
		bool isValidValue(const std::string &value);
		
		class DataOpenFailed : public std::exception {
			public:
				const char* what() const throw() { return "Error: could not open data file.";}
		};

		class InputOpenFailed : public std::exception {
			public:
				const char* what() const throw() { return "Error: could not open file.";}
		};

		class InvalidDate : public std::exception {
			public:
				const char* what() const throw() { return "Error: Invalid date.";}
		};

		class InvalidValue : public std::exception {
			public:
				const char* what() const throw() { return "Error: Invalid value.";}
		};
		
		class NegativeValue : public std::exception {
			public:
				const char* what() const throw() { return "Error: not a positive number.";}
		};

		class TooLargeValue : public std::exception {
			public:
				const char* what() const throw() { return "Error: too large a number.";}
		};
};