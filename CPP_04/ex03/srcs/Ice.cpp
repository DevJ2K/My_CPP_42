/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:08:42 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/05 12:03:45 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>
#include "Colors.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << BHCYAN << "New Ice materia create !" << RESET << std::endl;
	this->_type = "ice";
	return ;
}

Ice::Ice( Ice const & src ) : AMateria("ice")
{
	std::cout << BHYELLOW << "New Ice materia has been create from an other one !" << RESET << std::endl;
	*this = src;
	return ;
}

Ice::~Ice()
{
	std::cout << BHRED << "Ice materia has been destroyed !" << RESET << std::endl;
	return ;
}

Ice	&Ice::operator=( Ice const & rhs )
{
	this->_type = rhs.getType();
	return (*this);
}

Ice* Ice::clone( void ) const
{
	Ice*	iceClone = new Ice();
	*iceClone = (*this);
	return (iceClone);
}