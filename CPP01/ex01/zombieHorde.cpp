/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:06:07 by oztozdem          #+#    #+#             */
/*   Updated: 2025/08/22 12:50:15 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>

void	Zombie::setName(std::string name) {
	this->_name = name;
}

Zombie*	zombieHorde(int N, std::string name) {
	Zombie* zombie = NULL;
	
	zombie = new Zombie[N];
	
	for (int i = 0; i < N; i++)
		zombie[i].setName(name);
	
	return zombie;
}

// Zombie*	zombieHorde(int N, std::string name) {
// 	Zombie* zombie = NULL;
	
// 	try {
// 		zombie = new Zombie[N]; 
// 	} catch (const std::bad_alloc&) {
// 		return (NULL);
// 	}
	
// 	for (int i = 0; i < N; i++)
// 		zombie[i].setName(name);
	
// 	return zombie;
// }