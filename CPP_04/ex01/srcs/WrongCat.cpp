/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:24:05 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 14:40:05 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Colors.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << BGREEN << "WrongCat constructor called !" << RESET << std::endl;
}

WrongCat::WrongCat( WrongCat const & src ) : WrongAnimal(src)
{
	std::cout << BYELLOW << "WrongCat copy constructor called !" << RESET << std::endl;
	*this = src;
	return ;
}

WrongCat::~WrongCat()
{
	std::cout << BRED << "WrongCat destructor called !" << RESET << std::endl;
	return ;
}

WrongCat	&WrongCat::operator=( WrongCat const & rhs )
{
	std::cout << YELLOW << "WrongCat assignation operator called !" << RESET << std::endl;
	this->type = rhs.getType();
	return (*this);
}

std::string	WrongCat::getType( void ) const
{
	return (this->type);
}