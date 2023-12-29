/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:10:10 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/29 15:52:26 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Colors.hpp"
#include <iostream>

Zombie::Zombie( std::string name ) : _name(name)
{
	std::cout << GREEN << "Un nouveau zombie est ne, bienvenue au monde "<< RESET
	<< BHGREEN << this->_name << RESET << GREEN << " !" << RESET << std::endl;
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
