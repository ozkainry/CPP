/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:10:23 by oztozdem          #+#    #+#             */
/*   Updated: 2025/10/08 15:31:40 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {

	std::cout << "=== Good tests ===\n" << std::endl;

	Animal *meta = new Animal();
	Animal *j = new Dog();
	Animal *i = new Cat();

	std::cout << std::endl;
	std::cout << j->getType() << ": ";
	j->makeSound();
	std::cout << std::endl;
	std::cout << i->getType() << ": ";
	i->makeSound();
	std::cout << std::endl;
	std::cout << meta->getType() << ": ";
	meta->makeSound();
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;

	std::cout << "\n=== Wrong tests ===\n" << std::endl;

	WrongAnimal *wrongmeta = new WrongAnimal();
	WrongAnimal *wrongj = new WrongCat();

	std::cout << std::endl;
	std::cout << wrongj->getType() << ": ";
	wrongj->makeSound();
	std::cout << std::endl;
	std::cout << wrongmeta->getType() << ": ";
	wrongmeta->makeSound();
	std::cout << std::endl;

	delete wrongj;
	delete wrongmeta;

	std::cout << "\n=== Simple copy and assignment tests ===\n" << std::endl;

	Dog dog;
	Dog dog2(dog);
	std::cout << std::endl;
	dog2.makeSound();
	std::cout << std::endl;

	Cat cat;
	Cat cat2;
	cat2 = cat;
	std::cout << std::endl;
	cat2.makeSound();
	std::cout << std::endl;

	std::cout << "=== End of tests ===\n" << std::endl;

	return 0;
}