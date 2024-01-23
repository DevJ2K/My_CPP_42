/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:04:01 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 17:08:15 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "Colors.hpp"
#include <iostream>

A::A() : Base()
{
	this->displayType();
}

A::~A()
{
}

void A::displayType( void ) const
{
	std::cout << BHCYAN << "I'm a class [A]" << RESET << std::endl;
}
