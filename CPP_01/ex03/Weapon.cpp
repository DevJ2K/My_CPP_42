/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:20:28 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/30 11:24:16 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "Colors.hpp"

Weapon::Weapon( std::string type ) : _type(type)
{
	std::cout << BHWHITE << "New Weapon create : " << RESET
	<< BHCYAN << type << RESET << std::endl;
}

Weapon::~Weapon()
{
	std::cout << BHRED << this->_type << RESET << BRED
	<< " was destroy !" << RESET << std::endl;
}

void	Weapon::setType( std::string type )
{
	this->_type = type;
}

std::string const & Weapon::getType( void )
{
	return (this->_type);
}
