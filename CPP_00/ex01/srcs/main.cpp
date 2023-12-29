/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:59:11 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/29 11:56:00 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook myPhoneBook;
	std::string input;

	while (1)
	{
		std::cout << BHWHITE << "Entrez votre commande -> " << RESET;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << BHRED << "Pas de CTRL - D !" << RESET << std::endl;
			break;
		}
		if (input.empty())
		{
			std::cout << BHRED << "Attention aux champs vides !" << RESET << std::endl;
			continue ;
		}

		if (input.compare("ADD") == 0)
			myPhoneBook.addContact();

		if (input.compare("SEARCH") == 0)
			myPhoneBook.searchContact();

		if (input.compare("EXIT") == 0)
			break ;
	}

}
