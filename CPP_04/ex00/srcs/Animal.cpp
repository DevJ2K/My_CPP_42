/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:42:15 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 13:03:56 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Colors.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << BHGREEN << "Animal constructor called !" << RESET << std::endl;
}

Animal::Animal( Animal const & src )
{
	*this = src;
	return ;
}

Animal::~Animal()
{
}

Animal	&Animal::operator=( Animal const & rhs )
{
	return (*this);
}

std::string	Animal::getType( void )
{

}
void	Animal::makeSound( void )
{

}