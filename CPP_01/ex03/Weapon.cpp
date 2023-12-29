/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:20:28 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/29 18:29:33 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(/* args */)
{
}

Weapon::~Weapon()
{
}

void	Weapon::setType( std::string type )
{
	this->_type = type;
}

std::string const & Weapon::getType( void )
{
	return (this->_type);
}
