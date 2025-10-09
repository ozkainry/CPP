/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:35:44 by oztozdem          #+#    #+#             */
/*   Updated: 2025/08/22 12:41:53 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook {
	private:
		Contact contact[8];
		int	_total_contacts;
		int	_index;

	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	searchContacts() const;
};

#endif