/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:44:23 by oztozdem          #+#    #+#             */
/*   Updated: 2025/12/10 15:14:58 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <stack>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack() {};
		MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {};
		MutantStack& operator=(const MutantStack& other) {
			if (this != &other)
				std::stack<T, Container>::operator=(other);
			return *this;
		};
		~MutantStack() {};

		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		iterator begin() {
			return this->c.begin();
		};
		iterator end() {
			return this->c.end();
		};
};