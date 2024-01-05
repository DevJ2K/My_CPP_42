/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:43:06 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/05 10:04:24 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Colors.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << BGREEN << "Dog constructor called !" << RESET << std::endl;
}

Dog::Dog( Dog const & src ) : Animal(src)
{
	this->_brain = NULL;
	std::cout << BYELLOW << "Dog copy constructor called !" << RESET << std::endl;
	*this = src;
	return ;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << BRED << "Dog destructor called !" << RESET << std::endl;
	return ;
}

Dog	&Dog::operator=( Dog const & rhs )
{
	std::cout << YELLOW << "Dog assignation operator called !" << RESET << std::endl;
	if (this == &rhs)
		return (*this);
	this->type = rhs.getType();
	if (this->_brain != NULL)
		delete this->_brain;
	this->_brain = new Brain(*rhs.getBrain());
	return (*this);
}

std::string	Dog::getType( void ) const
{
	return (this->type);
}

Brain*	Dog::getBrain( void ) const
{
	return (this->_brain);
}

void	Dog::makeSound( void ) const
{
	std::cout << MAGHB << "WAF WAF !!" << RESET << std::endl;
	return ;
}