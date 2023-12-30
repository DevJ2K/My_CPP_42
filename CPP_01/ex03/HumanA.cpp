/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:23:10 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/30 14:00:22 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Colors.hpp"

HumanA::HumanA( std::string name, Weapon & weapon ) : _name(name), _weapon(weapon)
{
	std::cout << "New human is born with a "
	BHCYAN << weapon.getType() << RESET << ", welcome "
	<< BHYELLOW << name << RESET << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "A human was destroyed, "
	<< BHYELLOW << this->_name << RESET << std::endl;
}

void	HumanA::attack( void )
{
	std::cout << BHYELLOW << this->_name << RESET
	<< BHWHITE << " attacks with their " << RESET
	<< BHRED << this->_weapon.getType() << RESET << std::endl;
}
