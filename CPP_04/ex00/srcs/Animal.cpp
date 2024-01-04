/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:42:15 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 14:07:44 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Colors.hpp"
#include <iostream>

Animal::Animal() : type("Default")
{
	std::cout << BHGREEN << "Animal constructor called !" << RESET << std::endl;
	return ;
}

Animal::Animal( Animal const & src )
{
	std::cout << BHYELLOW << "Animal copy constructor called !" << RESET << std::endl;
	*this = src;
	return ;
}

Animal::~Animal()
{
	std::cout << BHRED << "Animal destructor called !" << RESET << std::endl;
	return ;
}

Animal	&Animal::operator=( Animal const & rhs )
{
	std::cout << BYELLOW << "Animal assignation operator called !" << RESET << std::endl;
	this->type = rhs.getType();
	return (*this);
}

std::string	Animal::getType( void ) const
{
	return (this->type);
}
void	Animal::makeSound( void ) const
{
	std::cout << BHMAG << "I'm suppose to do which sound ??" << RESET << std::endl;
	return ;
}