/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:18:59 by oztozdem          #+#    #+#             */
/*   Updated: 2025/08/22 12:44:03 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact {
	private:
		std::string	_first_name;
		std::string	_surname;
		std::string	_nickname;
		std::string	_phone;
		std::string	_secret;

	public:
		Contact();
		~Contact();
		void	setInfos();
		std::string	getFirstName() const;
		std::string	getSurname() const;
		std::string	getNickname() const;
		void	display() const;
};

#endif