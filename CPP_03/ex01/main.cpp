/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:00:49 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 09:47:48 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

static void	scav_attack_clap(ScavTrap *scav, ClapTrap *clap)
{
	if (clap->getHitPoints() > 0)
	{
		scav->attack(clap->getName());
		clap->takeDamage(scav->getAttackDamage());
	}
	else
		std::cout << BHRED << clap->getName() << " is already dead !" << RESET << std::endl;
}

int	main(void)
{
	ScavTrap scav("Scav_J2K");
	ClapTrap clap("Clap_Opps");

	// Scav attaque Clap
	for (size_t i = 0; i < 2; i++)
		scav_attack_clap(&scav, &clap);

	// Capacite propre a ScavTrap
	scav.guardGate();

	for (size_t i = 0; i < 5; i++)
		scav.beRepaired(20);

	for (size_t i = 0; i < 5; i++)
		scav.takeDamage(40);

	scav.guardGate();
}