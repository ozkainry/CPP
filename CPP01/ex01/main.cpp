/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:24:55 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/01 11:26:26 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	int	N = 10;
	Zombie* horde = zombieHorde(N, "Victor");
	
	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde;
	return 0;
}