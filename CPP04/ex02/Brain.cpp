/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:46:37 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/04 16:19:57 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
	std::cout	<< "A brain has formed!"
				<< std::endl;
}

Brain::Brain(Brain const& other) {
	for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	std::cout	<< "A brain has been perfectly cloned!"
				<< std::endl;
}

Brain::~Brain() {
	std::cout	<< "A brain's thoughts have faded into silence..."
				<< std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

void Brain::setIdeas(int index, std::string idea) {
	if (index >= 0 && index < 100)
		ideas[index] = idea;
	else
		std::cerr	<< "Error: invalid index " << index 
		        	<< " (0-99)" << std::endl;
}

std::string Brain::getIdeas(int index) {
	if (index < 0 || index >= 100)
		return "Error: index out of range (0-99)";
	if (ideas[index].empty())
		return "Error: no idea set at this index";
	return ideas[index];
}