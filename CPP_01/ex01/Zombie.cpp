/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:10:10 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/29 16:33:55 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Colors.hpp"
#include <iostream>

Zombie::Zombie()
{
	std::cout << GREEN << "Un nouveau zombie est ne, bienvenue au monde !"
	<< RESET << std::endl;
}

Zombie::~Zombie()
{
	std::cout << RED << "Un zombie est mort. RIP "
	<< RESET << BHRED << this->_name << RED
	<< ", on pensera pas a toi ..." << RESET << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << BHCYAN << this->_name << RESET << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name )
{
	this->_name = name;
}
