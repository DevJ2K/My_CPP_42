/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:08:47 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 17:09:05 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"
#include "Colors.hpp"
#include <iostream>

C::C() : Base()
{
	this->displayType();
}

C::~C()
{
}

void C::displayType( void ) const
{
	std::cout << BHMAG << "I'm a class [C]" << RESET << std::endl;
}
