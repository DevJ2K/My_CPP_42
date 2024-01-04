/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:47:29 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 14:13:17 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Colors.hpp"
#include <iostream>

Cat::Cat()
{
	this->type = "Cat";
	std::cout << BGREEN << "Cat constructor called !" << RESET << std::endl;
}

Cat::Cat( Cat const & src )
{
	std::cout << BYELLOW << "Cat copy constructor called !" << RESET << std::endl;
	*this = src;
	return ;
}

Cat::~Cat()
{
	std::cout << BRED << "Cat destructor called !" << RESET << std::endl;
	return ;
}

Cat	&Cat::operator=( Cat const & rhs )
{
	std::cout << YELLOW << "Cat assignation operator called !" << RESET << std::endl;
	this->type = rhs.getType();
	return (*this);
}

std::string	Cat::getType( void ) const
{
	return (this->type);
}
void	Cat::makeSound( void ) const
{
	std::cout << MAGB << "MIAOU MIAOU !!" << RESET << std::endl;
	return ;
}