/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:10:23 by oztozdem          #+#    #+#             */
/*   Updated: 2025/10/08 16:40:18 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int	main() {

	std::cout << "=== Array of Animals test ===" << std::endl;

	int size = 10;
	Animal* animals[size];

	for (int idx = 0; idx < size / 2; ++idx)
		animals[idx] = new Dog();
	for (int idx = size / 2; idx < size; ++idx)
		animals[idx] = new Cat();

	std::cout << "\n=== Brain tests ===" << std::endl;

	Dog* dog1 = new Dog();
	Cat* cat1 = new Cat();

	Brain* dogBrain = dog1->getBrain();
	Brain* catBrain = cat1->getBrain();

	std::cout << std::endl;
	if (dogBrain) {
		dogBrain->setIdeas(50, "Where is my toy?");
		dogBrain->setIdeas(150, "I want to go for a walk");

		std::cout << "Dog's idea 0: " << dogBrain->getIdeas(0) << std::endl;
		std::cout << "Dog's idea 50: " << dogBrain->getIdeas(50) << std::endl;
		std::cout << "Dog's idea 150: " << dogBrain->getIdeas(150) << std::endl;
	}
	std::cout << std::endl;
	if (catBrain) {
		catBrain->setIdeas(5, "I need to knock things off the table");
		catBrain->setIdeas(105, "Time for a 20-hour nap");

		std::cout << "Cat's idea 5: " << catBrain->getIdeas(5) << std::endl;
		std::cout << "Cat's idea 42: " << catBrain->getIdeas(42) << std::endl;
		std::cout << "Cat's idea 105: " << catBrain->getIdeas(105) << std::endl;
	}

	std::cout << "\n=== Copy tests ===" << std::endl;

	Dog dog2(*dog1);
	dog2.getBrain()->setIdeas(0, "Copy dog idea");
	std::cout << std::endl;
	std::cout << "dog1 idea 0: " << dog1->getBrain()->getIdeas(0) << std::endl;
	std::cout << "dog2 idea 0: " << dog2.getBrain()->getIdeas(0) << std::endl;
	std::cout << std::endl;
	
	Cat cat2;
	cat2 = *cat1;
	cat2.getBrain()->setIdeas(5, "Assigned cat idea");
	std::cout << std::endl;
	std::cout << "cat1 idea 5: " << cat1->getBrain()->getIdeas(5) << std::endl;
	std::cout << "cat2 idea 5: " << cat2.getBrain()->getIdeas(5) << std::endl;
	std::cout << std::endl;

	delete dog1;
	delete cat1;

	std::cout << "\n=== Deleting the Animals array ===" << std::endl;

	for (int idx = 0; idx < size; ++idx)
		delete animals[idx];

	std::cout << "\n=== End of tests ===" << std::endl;
	
	return 0;
}