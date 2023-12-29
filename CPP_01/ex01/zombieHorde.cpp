/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:12:22 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/29 16:37:00 by tajavon          ###   ########.fr       */
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
	return (&zombieTab[0]);
}
