/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:23:22 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/30 13:57:45 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Colors.hpp"

HumanB::HumanB( std::string name ) : _name(name)
{
	std::cout << "New human is born, welcome "
	<< BHGREEN << name << RESET << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "A human was destroyed, "
	<< BHGREEN << this->_name << RESET << std::endl;
}

void	HumanB::attack( void )
{
	std::cout << BHGREEN << this->_name << RESET
	<< BHWHITE << " attacks with ";
	if ((this->_weapon) == NULL)
		std::cout << "his " << RESET << BHRED << "hands" << RESET;
	else
	std::cout << "their " << RESET << BHRED << (*this->_weapon).getType() << RESET;
	std::cout << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->_weapon = &weapon;
	std::cout << BHGREEN << this->_name << RESET << " has equipped ";
	if (this->_weapon == NULL)
		std::cout << BHBLUE << "nothing." << RESET;
	else
		std::cout << BHBLUE << (*this->_weapon).getType() << RESET;
	std::cout << std::endl;
}

void	HumanB::removeWeapon( void )
{
	this->_weapon = NULL;
	std::cout << BHGREEN << this->_name << RESET << " has dropped his weapons. ";
	std::cout << std::endl;
}
