/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:33:13 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 20:58:13 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Colors.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << MAGB << "Brain constructor called !" << RESET << std::endl;
	return ;
}

Brain::Brain( Brain const & src )
{
	std::cout << BMAG << "Brain copy constructor called !" << RESET << std::endl;
	*this = src;
	return ;
}

Brain::~Brain()
{
	std::cout << REDB << "Brain destructor called !" << RESET << std::endl;
	return ;
}


Brain	&Brain::operator=( Brain const & rhs )
{
	for (size_t i = 0; i < this->_nb_ideas ; i++)
		this->_ideas[i] = rhs.getIdeas(i);

	std::cout << MAG << "Brain assignation operator called !" << RESET << std::endl;
	return (*this);
}

std::string	Brain::getIdeas( int index ) const
{
	return (this->_ideas[index]);
}

int	Brain::getNbIdeas( void ) const
{
	return (this->_nb_ideas);
}

void		Brain::setIdeas( int index, std::string ideas )
{
	this->_ideas[index] = ideas;
	return ;
}