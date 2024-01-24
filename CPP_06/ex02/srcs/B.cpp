/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:08:21 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/24 09:13:31 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"
#include "Colors.hpp"
#include <iostream>

B::B() : Base()
{
	std::cout << BHGREEN << "New instance of class [B] was created !" << RESET << std::endl;
}

B::~B()
{
}

void B::displayType( void ) const
{
	std::cout << BHYELLOW << "I'm a class [B]" << RESET << std::endl;
}
