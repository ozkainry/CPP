/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:24:55 by oztozdem          #+#    #+#             */
/*   Updated: 2025/08/22 12:47:37 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void) {
	Zombie first("Caspar");
	Zombie second("Victor");
	Zombie zombie;
	
	first.announce();
	second.announce();
	zombie.announce();
	randomChump("Oz");
	
	std::cout << std::endl;
	
	Zombie* third = newZombie("Pierre");
	Zombie* fourth = newZombie("Lucas");

	third->announce();
	fourth->announce();

	delete third;
	delete fourth;
	std::cout << std::endl;
	
	return 0;
}