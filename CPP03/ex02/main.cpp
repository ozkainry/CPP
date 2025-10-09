/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:10:23 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/09 11:43:06 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"
#include <iostream>

int main(void) {
	
	std::cout << "\n=== FragTrap in action ===\n" << std::endl;

	FragTrap frag("FragTrap");
	frag.attack("Handsome Jack");
	frag.highFivesGuys();
	frag.takeDamage(50);
	frag.beRepaired(30);
	frag.highFivesGuys();
	frag.takeDamage(100);

    std::cout << "\n=== Testing copy constructor ===\n" << std::endl;
    FragTrap frag2(frag);
    frag2.attack("Bandit");
    frag2.highFivesGuys();

    std::cout << "\n=== Testing assignment operator ===\n" << std::endl;
    FragTrap frag3("Temporary");
    frag3 = frag;
    frag3.attack("Psycho");
    frag3.highFivesGuys();
	
	std::cout << "\n=== End of simulation ===\n" << std::endl;

	return 0;
}