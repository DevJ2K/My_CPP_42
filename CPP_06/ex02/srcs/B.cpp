/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:08:21 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 17:08:44 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"
#include "Colors.hpp"
#include <iostream>

B::B() : Base()
{
	this->displayType();
}

B::~B()
{
}

void B::displayType( void ) const
{
	std::cout << BHYELLOW << "I'm a class [B]" << RESET << std::endl;
}
