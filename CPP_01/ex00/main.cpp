/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:39:12 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/29 16:07:23 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main(void)
{
	std::string	tab[5];
	tab[0] = "Gucci";
	tab[1] = "Lacoste";
	tab[2] = "Nike";
	tab[3] = "Adidas";
	tab[4] = "Puma";
	for (size_t i = 0; i < 5; i++)
		randomChump(tab[i]);

	Zombie*	zmb1 = newZombie("Zombie1");
	Zombie*	zmb2 = newZombie("Zombie2");
	Zombie*	zmb3 = newZombie("Zombie3");
	Zombie*	zmb4 = newZombie("Zombie4");
	Zombie*	zmb5 = newZombie("Zombie5");

	delete zmb1;
	delete zmb2;
	delete zmb3;
	delete zmb4;
	delete zmb5;

}
