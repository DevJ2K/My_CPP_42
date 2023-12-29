/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:48:13 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/28 15:56:01 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"
#include "Colors.hpp"

class PhoneBook
{
	private:
		Contact	_contactList[8];
		int		_addIndex;
		int		_nbContacts;
	public:
		PhoneBook();
		~PhoneBook();

		void	addContact( void );
		void	searchContact ( void );
};

#endif
