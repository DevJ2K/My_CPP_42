/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:42:15 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/05 10:54:00 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Colors.hpp"
#include <iostream>

AAnimal::AAnimal()
{
	std::cout << BHGREEN << "AAnimal constructor called !" << RESET << std::endl;
	return ;
}

AAnimal::AAnimal( AAnimal const & src )
{
	std::cout << BHYELLOW << "AAnimal copy constructor called !" << RESET << std::endl;
	*this = src;
	return ;
}

AAnimal::~AAnimal()
{
	std::cout << BHRED << "AAnimal destructor called !" << RESET << std::endl;
	return ;
}

AAnimal	&AAnimal::operator=( AAnimal const & rhs )
{
	std::cout << BYELLOW << "AAnimal assignation operator called !" << RESET << std::endl;
	this->type = rhs.getType();
	return (*this);
}

std::string	AAnimal::getType( void ) const
{
	return (this->type);
}