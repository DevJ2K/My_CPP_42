/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:39:12 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/29 16:46:38 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Colors.hpp"
#include <iostream>
#include <sstream>

Zombie*	zombieHorde( int N, std::string name );

int	main(void)
{
	std::string	string_nb;
	int			nb;
	std::string	name;

	std::cout << BHBLUE << "Combien de Zombies souhaitez-vous creer ? -> " << RESET;
	std::cin >> string_nb;

	std::istringstream	iss(string_nb);
	iss >> nb;

	std::cout << BHCYAN << "Comment souhaitez-vous tous les appeler ? -> " << RESET;
	std::cin >> name;
	Zombie* myZombie = zombieHorde(nb, name);

	delete [] myZombie;
}
