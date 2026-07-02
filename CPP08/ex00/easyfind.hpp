/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:35:33 by oztozdem          #+#    #+#             */
/*   Updated: 2025/12/01 16:30:03 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception {
	public:
		const char* what() const throw() { return "The number was not found"; }
};

template<typename T>
typename T::iterator easyfind(T& find, int i) {
	typename T::iterator search = std::find(find.begin(), find.end(), i);
	
	if (search == find.end())
		throw NotFoundException();
	return search;
}