/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:34:27 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/01 12:28:36 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void) {
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout	<< &string << std::endl
				<< stringPTR << std::endl
				<< &stringREF << std::endl;

	std::cout	<< string << std::endl
				<< *stringPTR << std::endl
				<< stringREF << std::endl;
	return 0;
}