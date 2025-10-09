/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:10:23 by oztozdem          #+#    #+#             */
/*   Updated: 2025/10/09 15:38:21 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main() {

	std::cout << "\n=== Good tests ===" << std::endl;

	Animal* j = new Dog();
	Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << j->getType() << ": ";
	j->makeSound();
	std::cout << std::endl;
	std::cout << i->getType() << ": ";
	i->makeSound();
	std::cout << std::endl;
	std::cout << std::endl;

	delete j;
	delete i;

	std::cout << "=== End of good tests ===" << std::endl;

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

	std::cout << "=== End of brain tests ===" << std::endl;

	std::cout << "\n=== Wrong tests ===" << std::endl;

	WrongAnimal* wrongmeta = new WrongAnimal();
	WrongAnimal* wrongj = new WrongCat();

	std::cout << std::endl;
	std::cout << wrongj->getType() << ": ";
	wrongj->makeSound();
	std::cout << std::endl;
	std::cout << wrongmeta->getType() << ": ";
	wrongmeta->makeSound();
	std::cout << std::endl;

	delete wrongj;
	delete wrongmeta;

	std::cout << "=== End of wrong tests ===\n" << std::endl;

	delete dog1;
	delete cat1;
	
	return 0;
}