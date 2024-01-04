/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:00:49 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 09:58:42 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static void	frag_attack_clap(FragTrap *frag, ClapTrap *clap)
{
	if (clap->getHitPoints() > 0)
	{
		frag->attack(clap->getName());
		clap->takeDamage(frag->getAttackDamage());
	}
	else
		std::cout << BHRED << clap->getName() << " is already dead !" << RESET << std::endl;
}

int	main(void)
{
	FragTrap frag("frag_J2K");
	ClapTrap clap("Clap_Opps");

	// frag attaque Clap
	for (size_t i = 0; i < 2; i++)
		frag_attack_clap(&frag, &clap);

	// Capacite propre a FragTrap
	frag.highFivesGuys();

	for (size_t i = 0; i < 5; i++)
		frag.beRepaired(20);

	for (size_t i = 0; i < 6; i++)
		frag.takeDamage(40);

	frag.highFivesGuys();
}