/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:10:23 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/09 11:37:15 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
	
	std::cout << "\n=== ScavTrap in action ===\n" << std::endl;
	
	ScavTrap scav("ScavTrap");
	scav.attack("Handsome Jack");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();
	scav.takeDamage(90);

	std::cout << "\n=== Testing copy constructor ===\n" << std::endl;
    ScavTrap scav2(scav);
    scav2.attack("Bandit");
    scav2.guardGate();

    std::cout << "\n=== Testing assignment operator ===\n" << std::endl;
    ScavTrap scav3("Temporary");
    scav3 = scav;
    scav3.attack("Psycho");
    scav3.guardGate();
	
	std::cout << "\n=== End of simulation ===\n" << std::endl;

	return 0;
}