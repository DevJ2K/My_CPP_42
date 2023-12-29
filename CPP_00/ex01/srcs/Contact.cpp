/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:59:08 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/28 17:13:00 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Colors.hpp"

Contact::Contact(void) : _firstName(""), _lastName(""), _nickname(""), _phoneNumber("")
{
	std::cout << BHGREEN << "Constructor Contact called" << RESET << std::endl;
	return ;
}

Contact::~Contact()
{
	std::cout << BHRED << "Destructor Contact called" << RESET << std::endl;
	return ;
}

void	Contact::displayContact(void) const
{
	std::cout << this->_firstName << RESET << std::endl;
	std::cout << this->_lastName << RESET << std::endl;
	std::cout << this->_nickname << RESET << std::endl;
	std::cout << this->_phoneNumber << RESET << std::endl;
	return ;
}

std::string	Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string	Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string	Contact::getNickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}


void	Contact::setInfoContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darksetSecret)
{
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_darksetSecret = darksetSecret;
	return ;
}
