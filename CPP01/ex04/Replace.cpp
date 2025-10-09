/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:40:04 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/01 11:40:20 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <string>

std::string	replace(const std::string& line, const std::string& s1, const std::string& s2) {
	std::string result = line;
	size_t pos = 0;
	while ((pos = result.find(s1, pos)) != std::string::npos) {
		result = result.substr(0, pos) + s2 + result.substr(pos + s1.length());
		pos += s2.length();
	}
	return result;
}