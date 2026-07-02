/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:13:14 by oztozdem          #+#    #+#             */
/*   Updated: 2025/12/10 15:37:55 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void) {
	std::cout << "=== MutantStack test ===" << std::endl;
	
	{
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();
		
		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(91);
		mstack.push(42);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "\n=== std::list test ===" << std::endl;
	
	{
		std::list<int> lst;
		
		lst.push_back(5);
		lst.push_back(17);

		std::cout << lst.back() << std::endl;

		lst.pop_back();
		
		std::cout << lst.size() << std::endl;
		
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(91);
		lst.push_back(42);
		lst.push_back(737);
		lst.push_back(0);

		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	
	return 0;
}
