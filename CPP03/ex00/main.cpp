/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:10:23 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/09 11:25:59 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void) {
	ClapTrap clap("ClapTrap");

	std::cout << std::endl;
	std::cout << "\n=== ClapTrap in action ===\n" << std::endl;
	
	clap.attack("Handsome Jack");
	clap.takeDamage(5);
	clap.beRepaired(4);
	clap.takeDamage(9);

	std::cout << "\n=== Testing copy constructor ===\n" << std::endl;
    ClapTrap clap2(clap);
    clap2.attack("Bandit");

    std::cout << "\n=== Testing assignment operator ===\n" << std::endl;
    ClapTrap clap3("Temporary");
    clap3 = clap;
    clap3.attack("Psycho");
	
	std::cout << "\n=== End of simulation ===\n" << std::endl;
	
	return 0;
}