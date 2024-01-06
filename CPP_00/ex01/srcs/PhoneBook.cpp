/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:59:14 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/06 17:42:00 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Colors.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook(void) : _addIndex(0), _nbContacts(0)
{
	std::cout << BHGREEN << "Constructor PhoneBook called" << RESET << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << BHRED << "Destructor PhoneBook called" << RESET << std::endl;
}

bool	checkValidNumber(std::string phoneNumber)
{
	if (phoneNumber.length() != 10)
		return (0);
	if (phoneNumber[0] != '0' || phoneNumber[1] == '0')
		return (0);
	return (1);
}

bool	checkOnlyLetters(std::string str)
{
	if (str.empty())
		return (0);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isalpha(str[i]) == 0)
			return (0);
	}
	return (1);
}

bool	checkOnlyDigits(std::string str)
{
	if (str.empty())
		return (0);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
}


void	PhoneBook::addContact(void)
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darksetSecret;

	while (1)
	{
		std::cout << "Prenom : ";
		std::getline(std::cin, firstName);
		if (std::cin.eof())
		{
			std::cout << std::endl << BHRED << "[CTRL - D]: Sorti de programme demandé !" << RESET << std::endl;
			exit (1);
		}
		if (firstName.empty() || checkOnlyLetters(firstName) == false)
		{
			std::cout << BHRED << "Veuillez mettre un prenom valide !" << RESET << std::endl;
			continue;
		}
		break;
	}

	while (1)
	{
		std::cout << "Nom : ";
		std::getline(std::cin, lastName);
		if (std::cin.eof())
		{
			std::cout << std::endl << BHRED << "[CTRL - D]: Sorti de programme demandé !" << RESET << std::endl;
			exit (1);
		}
		if (lastName.empty() || checkOnlyLetters(lastName) == false)
		{
			std::cout << BHRED << "Veuillez mettre un nom valide !" << RESET << std::endl;
			continue;
		}
		break;
	}

	while (1)
	{
		std::cout << "Surnom : ";
		std::getline(std::cin, nickname);
		if (std::cin.eof())
		{
			std::cout << std::endl << BHRED << "[CTRL - D]: Sorti de programme demandé !" << RESET << std::endl;
			exit (1);
		}
		if (nickname.empty())
		{
			std::cout << BHRED << "Veuillez mettre un surnom !" << RESET << std::endl;
			continue;
		}
		break;
	}

	while (1)
	{
		std::cout << "Numero de telephone : ";
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof())
		{
			std::cout << std::endl << BHRED << "[CTRL - D]: Sorti de programme demandé !" << RESET << std::endl;
			exit (1);
		}
		if (phoneNumber.empty() || checkOnlyDigits(phoneNumber) == false || checkValidNumber(phoneNumber) == false)
		{
			std::cout << BHRED << "Veuillez mettre un numero de telephone valide !" << RESET << std::endl;
			continue;
		}
		break;
	}

	while (1)
	{
		std::cout << "Secret le plus lourd : ";
		std::getline(std::cin, darksetSecret);
		if (std::cin.eof())
		{
			std::cout << std::endl << BHRED << "[CTRL - D]: Sorti de programme demandé !" << RESET << std::endl;
			exit (1);
		}
		if (darksetSecret.empty())
		{
			std::cout << BHMAG << "Allez dis-nous ton secret, ca reste entre nous..." << RESET << std::endl;
			continue;
		}
		break;
	}

	this->_contactList[this->_addIndex].setInfoContact(firstName, lastName, nickname, phoneNumber, darksetSecret);
	if (this->_addIndex == 7)
	{
		this->_addIndex = 0;
		this->_nbContacts = 8;
	}
	else
	{
		this->_addIndex++;
		if (this->_nbContacts < 8)
			this->_nbContacts++;
	}
}

void	displayColumn(std::string prenom, std::string nom, std::string nickname, int i)
{
	if (prenom.length() > 10) {
		prenom.resize(9);
		prenom += ".";
	}
	if (nom.length() > 10) {
		nom.resize(9);
		nom += ".";
	}
	if (nickname.length() > 10) {
		nickname.resize(9);
		nickname += ".";
	}
	std::cout << std::setw(10) << i << "|";
	std::cout << std::setw(10) << prenom << "|";
	std::cout << std::setw(10) << nom << "|";
	std::cout << std::setw(10) << nickname << "|" << std::endl;
	return ;

}

int	convert_string_to_int(std::string str)
{
	int					n;
	std::istringstream	iss(str);

	iss >> n;
	return n;
}

void	PhoneBook::searchContact(void)
{
	if (this->_nbContacts == 0)
		return ;
	std::cout << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << "PRENOM" << "|";
	std::cout << std::setw(10) << "NOM" << "|";
	std::cout << std::setw(10) << "NICKNAME" << "|" << std::endl;
	for (int i = 0; i < this->_nbContacts; i++)
	{
		displayColumn(
			this->_contactList[i].getFirstName(),
			this->_contactList[i].getLastName(),
			this->_contactList[i].getNickname(),
			i
		);
	}

	std::cout << BHWHITE << "Entrez l'index -> " << RESET;
	std::string index;
	std::getline(std::cin, index);
	if (std::cin.eof())
	{
		std::cout << std::endl << BHRED << "[CTRL - D]: Sorti de programme demandé !" << RESET << std::endl;
		exit (1);
	}
	if (index.empty())
	{
		std::cout << BHRED << "Vous n'avez rentre aucun index !" << RESET << std::endl;
		return ;
	}
	if (checkOnlyDigits(index) == false)
	{
		std::cout << BHRED << "La valeur est invalide !" << RESET << std::endl;
		return ;
	}
	int i = convert_string_to_int(index);
	if (i >= this->_nbContacts || i < 0)
	{
		std::cout << BHRED << "L'utilisateur est introuvable !" << RESET << std::endl;
		return ;
	}
	this->_contactList[i].displayContact();
}

