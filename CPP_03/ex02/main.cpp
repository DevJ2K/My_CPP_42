/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:00:49 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/02 21:39:58 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap frag("J2K");

	frag.attack("Player");
	frag.highFivesGuys();
	for (size_t i = 0; i < 5; i++)
	{
		frag.beRepaired(20);
	}
	for (size_t i = 0; i < 5; i++)
	{
		frag.takeDamage(40);
	}
	frag.highFivesGuys();

	// for (size_t i = 0; i < 6; i++)
	// {
	// 	frag.takeDamage(i + 1);
	// 	frag.beRepaired(i);
	// }


	// frag.getAttackDamage();

	// frag.beRepaired(100);
}