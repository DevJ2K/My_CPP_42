/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:01:16 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/05 12:03:43 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>
#include "Colors.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << BHCYAN << "New Cure materia create !" << RESET << std::endl;
	this->_type = "cure";
	return ;
}

Cure::Cure( Cure const & src ) : AMateria("cure")
{
	std::cout << BHYELLOW << "New Cure materia has been create from an other one !" << RESET << std::endl;
	*this = src;
	return ;
}

Cure::~Cure()
{
	std::cout << BHRED << "Cure materia has been destroyed !" << RESET << std::endl;
	return ;
}

Cure	&Cure::operator=( Cure const & rhs )
{
	this->_type = rhs.getType();
	return (*this);
}

Cure* Cure::clone( void ) const
{
	Cure*	cureClone = new Cure();
	*cureClone = (*this);
	return (cureClone);
}