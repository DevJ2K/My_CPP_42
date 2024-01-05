/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:25:56 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/05 14:14:22 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Colors.hpp"
#include <iostream>

MateriaSource::MateriaSource() : _nb_items(0)
{
	std::cout << BHGREEN << "MateriaSource Constructor called !"<< RESET << std::endl;
	for (int i = 0; i < this->_size_inventory; i++)
		this->_inventory[i] = NULL;
	return ;
}

MateriaSource::MateriaSource( MateriaSource const & src )
{
	std::cout << BHYELLOW << "MateriaSource copy constructor called !"<< RESET << std::endl;
	for (int i = 0; i < this->_size_inventory; i++)
		this->_inventory[i] = NULL;
	*this = src;
	return ;
}

MateriaSource::~MateriaSource()
{
		for (int i = 0; i < this->_nb_items; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			std::cout << "Item deleted !" << std::endl;
		}
	}
	std::cout << BHRED << "MateriaSource destructor called ! : " << RESET << std::endl;
	return ;
}

MateriaSource	&MateriaSource::operator=( MateriaSource const & rhs )
{
	for (int i = 0; i < this->_size_inventory; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
	this->_nb_items = 0;
	for (int i = 0; rhs.getMateria(i); i++)
	{
		this->_inventory[i] = rhs.getMateria(i);
		this->_nb_items += 1;
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (this->_nb_items < this->_size_inventory)
	{
		this->_inventory[this->_nb_items] = m;
		this->_nb_items += 1;
		std::cout << BHGREEN << m->getType()
		<< " has learn and add to Materia Source !" << RESET << std::endl;

	}
	else
		std::cout << BHRED << "Your Materia Source is full ! Please create Materia !" << RESET << std::endl;

}

AMateria*	MateriaSource::getMateria(int idx) const
{
	if (idx > 0 && idx < this->_nb_items)
		return (this->_inventory[idx]);
	return (NULL);
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (this->_nb_items == 0)
	{
		std::cout << BHRED << "You cannot create Materia because you're Materia Source is empty !" << RESET << std::endl;
		return (NULL);
	}
	for (int i = this->_nb_items - 1; i >= 0; i--)
	{
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
		{
			std::cout << BHCYAN << "New Materia of type ["
			<< type << "] has been created !" << RESET << std::endl;
			return (this->_inventory[i]->clone());
		}
	}
	std::cout << BHRED << "Materia of type ["
	<< type << "] not found in Materia Source !" << RESET << std::endl;
	return (NULL);
}

