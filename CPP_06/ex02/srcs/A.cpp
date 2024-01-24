/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:04:01 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/24 09:13:24 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "Colors.hpp"
#include <iostream>

A::A() : Base()
{
	std::cout << BHGREEN << "New instance of class [A] was created !" << RESET << std::endl;
}

A::~A()
{
}

void A::displayType( void ) const
{
	std::cout << BHCYAN << "I'm a class [A]" << RESET << std::endl;
}
