/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:32:27 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/05 15:53:36 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>
#include "Colors.hpp"

Character::Character( std::string name ) : _name(name), _nb_items(0)
{
	std::cout << BHGREEN << "Character Constructor called ! : "
	<< RESET << BHWHITE << this->_name << RESET << std::endl;
	for (int i = 0; i < this->_size_inventory; i++)
		this->_inventory[i] = NULL;
}

Character::Character( Character const & src )
{
	std::cout << BHGREEN << "Character copy constructor called ! : "
	<< RESET << BHWHITE << src.getName() << RESET << std::endl;
	for (int i = 0; i < this->_size_inventory; i++)
		this->_inventory[i] = NULL;
	*this = src;
	return ;
}

Character::~Character()
{
	for (int i = 0; i < this->_size_inventory; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	std::cout << BHRED << "Character has been deleted ! : " << RESET
	<< REDHB << this->_name << RESET << std::endl;
}

Character	&Character::operator=( Character const & rhs )
{
	this->_name = rhs.getName();
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

std::string const & Character::getName() const
{
	return (this->_name);
}

void		Character::setName( std::string const & name )
{
	this->_name = name;
	return ;
}

int	Character::getInventorySize() const
{
	return (this->_size_inventory);
}

AMateria*	Character::getMateria(int idx) const
{
	if (idx > 0 && idx < this->_nb_items)
		return (this->_inventory[idx]);
	return (NULL);
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
		std::cout << BWHITE << "[Nothing has been add to your inventory...]" << RESET << std::endl;
	else if (this->_nb_items >= this->_size_inventory)
		std::cout << BHRED << "Your inventory is full ! Please unequip a Materia !" << RESET << std::endl;
	else
	{
		for (int i = 0; i < this->_size_inventory; i++)
		{
			if (this->_inventory[i] == NULL)
			{
				this->_inventory[i] = m;
				this->_nb_items += 1;
				std::cout << BHCYAN << m->getType() << RESET
				<< BHGREEN << " materia has been successfully add to your inventory !" << RESET << std::endl;
				return ;
			}
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0)
		std::cout << BHRED << "An index cannot be minus 0 !" << RESET << std::endl;
	else if (idx >= this->_size_inventory)
		std::cout << BHRED << "Index out of range of your inventory ("
		<< this->_size_inventory << ")!" << RESET << std::endl;
	else if (this->_inventory[idx])
	{
		this->_nb_items -= 1;
		std::cout << BHGREEN << this->_inventory[idx]->getType()
		<< " has been successfully delete of your inventory !" << RESET << std::endl;
		this->_inventory[idx] = NULL;

	}
	else
		std::cout << BHRED << "This slot is already !" << RESET << std::endl;

}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0)
		std::cout << BHRED << "An index cannot be minus 0 !" << RESET << std::endl;
	else if (idx >= this->_size_inventory)
	{
		std::cout << BHRED << "Index out of range of your inventory ("
		<< this->_size_inventory << ")!" << RESET << std::endl;
	}
	else if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << BHRED << "This slot is empty !" << RESET << std::endl;

}

void	Character::displayInventory( void ) const
{
	for (int i = 0; i < this->_size_inventory; i++)
	{
		std::cout << BHWHITE << "[Slot n*" << i
		<< "] : " << RESET;
		if (this->_inventory[i] == NULL)
			std::cout << BHWHITE << "EMPTY";
		else
			std::cout << BHCYAN << this->_inventory[i]->getType();
		std::cout << RESET << std::endl;
	}

}