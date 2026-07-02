/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:51:00 by oztozdem          #+#    #+#             */
/*   Updated: 2025/11/04 15:47:14 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void) {
	Data value;
    value.id = 42;
    value.name = "Caspar";

    std::cout << "value of Data value before serialization : " << &value << std::endl;
    uintptr_t raw = Serializer::serialize(&value);
    std::cout << "value of raw after serialization : " << raw << std::endl;
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Original pointer : " << &value << std::endl;
    std::cout << "Deserialized ptr : " << ptr << std::endl;

    if (ptr == &value)
        std::cout << "Pointers match!" << std::endl;
    else
        std::cout << "Pointers do not match." << std::endl;

    std::cout << "id: " << ptr->id << ", name: " << ptr->name << std::endl;
	
	return 0;
}