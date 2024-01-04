/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:42:15 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 14:40:34 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Colors.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << BHGREEN << "WrongAnimal constructor called !" << RESET << std::endl;
	return ;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src )
{
	std::cout << BHYELLOW << "WrongAnimal copy constructor called !" << RESET << std::endl;
	*this = src;
	return ;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << BHRED << "WrongAnimal destructor called !" << RESET << std::endl;
	return ;
}

WrongAnimal	&WrongAnimal::operator=( WrongAnimal const & rhs )
{
	std::cout << BYELLOW << "WrongAnimal assignation operator called !" << RESET << std::endl;
	this->type = rhs.getType();
	return (*this);
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->type);
}
void	WrongAnimal::makeSound( void ) const
{
	std::cout << REDB << "I'm a bad animal ahahhahahahah !!" << RESET << std::endl;
	return ;
}