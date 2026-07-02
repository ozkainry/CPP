/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:47:00 by oztozdem          #+#    #+#             */
/*   Updated: 2025/11/05 13:31:06 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>

int main(void) {
	srand(time(NULL));

    Base* obj = generate();

    identify(obj);
    identify(*obj);

    delete obj;

	return 0;
}