/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:02:11 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 12:07:13 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name )
	: ClapTrap(name + "_ClapTrap"), ScavTrap(name + "_ScavTrap"), FragTrap(name + "_FragTrap")
{
	std::cout << GREENB << "DiamondTrap constructor called with params : " << RESET << BHCYAN << name << RESET << std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	return ;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src )
	: ClapTrap(src.getName() + "_ClapTrap"), ScavTrap(src.getName() + "_ScavTrap"), FragTrap(src.getName() + "_FragTrap")
{
	std::cout << BHYELLOW << "DiamondTrap copy constructor called" << RESET << std::endl;
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	return ;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << REDB << "DiamondTrap destructor called" << RESET << std::endl;
	return ;
}

DiamondTrap	&DiamondTrap::operator=( DiamondTrap const & rhs )
{
	std::cout << YELLOW << "DiamondTrap assignation operator called" << std::endl;
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();
	return (*this);
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << BHWHITE << "Hi, my name is " << RESET << BHCYAN << this->_name << RESET << BHWHITE
	<< " and my ClapTrap name is " << RESET << BHMAG << ClapTrap::_name << RESET " !" << std::endl;
	return ;
}