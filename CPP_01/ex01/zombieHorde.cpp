/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:12:22 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/30 19:11:12 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	if (N == 0)
		return (NULL);
	Zombie*	zombieTab = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombieTab[i].setName(name);
	for (int i = 0; i < N; i++)
		zombieTab[i].announce();
	return (&zombieTab[0]);
}
