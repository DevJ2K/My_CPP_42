/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:43:36 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 09:38:48 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	std::cout << BGREEN << "ScavTrap constructor called with params : " << RESET << BHMAG << name << RESET << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap( ScavTrap const & src ) : ClapTrap(src)
{
	std::cout << BHYELLOW << "ScavTrap copy constructor called" << RESET << std::endl;
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	return ;
}

ScavTrap	&ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << YELLOW << "ScavTrap assignation operator called" << std::endl;
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();
	return (*this);
}

void	ScavTrap::guardGate( void )
{
	if (this->_check_life_and_energy("guard the gate") == false)
		return ;
	this->_energyPoints -= 1;
	std::cout << BHCYAN << this->getName() << ": " << RESET << BHMAG << "You're now in Gate keeper mode !" << RESET << std::endl;

}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_check_life_and_energy("attack") == false)
		return ;
	std::cout << BHWHITE << "ScavTrap " << RESET
	<< BHBLUE << this->getName() << RESET << BHWHITE
	<< " attacks "
	<< BHRED << target << RESET << BHWHITE ", causing "
	<< this->getAttackDamage() << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
	this->displayInfo();
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << BRED << "ScavTrap destructor called : " << RESET << BHMAG << this->getName() << RESET << std::endl;
	return ;
}
