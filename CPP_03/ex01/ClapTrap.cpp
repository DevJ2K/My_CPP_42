/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:56:23 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 09:37:22 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << BHGREEN << "ClapTrap constructor called with params : " << RESET << BHCYAN << name << RESET << std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap const & src )
{
	std::cout << BHYELLOW << "ClapTrap copy constructor called : " << RESET << BHCYAN << src.getName() << RESET << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << BHRED << "ClapTrap destructor called : " << RESET << BHCYAN << this->getName() << RESET << std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator=( ClapTrap const & rhs )
{
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();
	return (*this);
}

unsigned int	ClapTrap::getHitPoints( void ) const
{
	return (this->_hitPoints);
}
unsigned int	ClapTrap::getEnergyPoints( void ) const
{
	return (this->_energyPoints);
}
unsigned int	ClapTrap::getAttackDamage( void ) const
{
	return (this->_attackDamage);
}
std::string	ClapTrap::getName( void ) const
{
	return (this->_name);
}

bool	ClapTrap::_check_life_and_energy( std::string action ) const
{
	if (this->_hitPoints <= 0)
	{
		std::cout << RED << "You cannot " << action << " because you have not enough hit points." << RESET << std::endl;
		return (false);
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << RED << "You cannot " << action << " because you have not enough energy points." << RESET << std::endl;
		return (false);
	}
	return (true);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_check_life_and_energy("attack") == false)
		return ;
	std::cout << BHWHITE << "ClapTrap " << RESET
	<< BHBLUE << this->getName() << RESET << BHWHITE
	<< " attacks "
	<< BHRED << target << RESET << BHWHITE ", causing "
	<< this->getAttackDamage() << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
	this->displayInfo();
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << BHCYAN << this->getName() << ": " << RESET << RED << "You cannot take more damage because you have not enough hit points." << RESET << std::endl;
		return ;
	}
	if (amount >= this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << BHCYAN << this->getName() << ": " << RESET << YELLOW << "You lost " << amount << " hit points. Be careful !" << RESET << std::endl;
	this->displayInfo();
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_check_life_and_energy("be repaired") == false)
		return ;
	this->_energyPoints -= 1;
	this->_hitPoints += amount;
	std::cout << BHCYAN << this->getName() << ": " << RESET << GREEN << "You get " << amount << " hit points back !" << RESET << std::endl;
	this->displayInfo();
	return ;
}

void	ClapTrap::displayInfo( void ) const
{
	std::cout << BHCYAN << this->getName() << ": " << RESET << BHWHITE << "You have " << RESET
	<< BHMAG << this->getHitPoints() << "HP" << RESET << " and "
	<< BHYELLOW << this->getEnergyPoints() << " Energy Points !" << RESET << std::endl;
	return ;
}