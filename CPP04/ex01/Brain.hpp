/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:46:26 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/04 14:08:50 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(Brain const& other);
		~Brain();
		Brain& operator=(const Brain& other);

		void setIdeas(int index, std::string idea);
		std::string getIdeas(int index);
};