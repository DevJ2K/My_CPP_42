/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:47:29 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/05 10:04:10 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Colors.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << BGREEN << "Cat constructor called !" << RESET << std::endl;
}

Cat::Cat( Cat const & src ) : Animal(src)
{
	this->_brain = NULL;
	std::cout << BYELLOW << "Cat copy constructor called !" << RESET << std::endl;
	*this = src;
	return ;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << BRED << "Cat destructor called !" << RESET << std::endl;
	return ;
}

Cat	&Cat::operator=( Cat const & rhs )
{
	std::cout << YELLOW << "Cat assignation operator called !" << RESET << std::endl;
	if (this == &rhs)
		return (*this);
	this->type = rhs.getType();
	if (this->_brain != NULL)
		delete this->_brain;
	this->_brain = new Brain(*rhs.getBrain());
	return (*this);
}

std::string	Cat::getType( void ) const
{
	return (this->type);
}

Brain*	Cat::getBrain( void ) const
{
	return (this->_brain);
}

void	Cat::makeSound( void ) const
{
	std::cout << MAGB << "MIAOU MIAOU !!" << RESET << std::endl;
	return ;
}