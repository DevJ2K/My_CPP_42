/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:00:49 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/02 21:16:44 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap scav("J2K");

	scav.attack("Player");
	scav.guardGate();
	for (size_t i = 0; i < 5; i++)
	{
		scav.beRepaired(20);
	}
	for (size_t i = 0; i < 5; i++)
	{
		scav.takeDamage(40);
	}
	scav.guardGate();

	// for (size_t i = 0; i < 6; i++)
	// {
	// 	scav.takeDamage(i + 1);
	// 	scav.beRepaired(i);
	// }


	// scav.getAttackDamage();

	// scav.beRepaired(100);
}