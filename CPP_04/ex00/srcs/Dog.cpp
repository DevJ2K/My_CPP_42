/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:43:06 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 14:18:44 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Colors.hpp"
#include <iostream>

Dog::Dog()
{
	this->type = "Dog";
	std::cout << BGREEN << "Dog constructor called !" << RESET << std::endl;
}

Dog::Dog( Dog const & src )
{
	std::cout << BYELLOW << "Dog copy constructor called !" << RESET << std::endl;
	*this = src;
	return ;
}

Dog::~Dog()
{
	std::cout << BRED << "Dog destructor called !" << RESET << std::endl;
	return ;
}

Dog	&Dog::operator=( Dog const & rhs )
{
	std::cout << YELLOW << "Dog assignation operator called !" << RESET << std::endl;
	this->type = rhs.getType();
	return (*this);
}

std::string	Dog::getType( void ) const
{
	return (this->type);
}

void	Dog::makeSound( void ) const
{
	std::cout << MAGHB << "WAF WAF !!" << RESET << std::endl;
	return ;
}