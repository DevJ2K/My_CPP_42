/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:25:20 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/02 21:42:34 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout << BGREEN << "FragTrap constructor called with params : " << RESET << BHCYAN << name << RESET << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap( FragTrap const & src ) : ClapTrap(src)
{
	std::cout << BHYELLOW << "FragTrap copy constructor called" << RESET << std::endl;
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << BRED << "FragTrap destructor called : " << RESET << BHCYAN << this->getName() << RESET << std::endl;
	return ;
}

FragTrap&	FragTrap::operator=( FragTrap const & rhs )
{
	std::cout << YELLOW << "FragTrap assignation operator called" << std::endl;
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();
	return (*this);
}

void	FragTrap::highFivesGuys( void )
{
	if (this->_check_life_and_energy("do a high fives") == false)
		return ;
	this->_energyPoints -= 1;
	std::cout << BHWHITE << this->getName() << ": " << RESET
	<< BHMAG << "Hi, I want a high fives !!" << RESET << std::endl;

}