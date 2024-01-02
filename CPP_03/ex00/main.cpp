/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:00:49 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/02 19:42:20 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap clap("J2K");

	clap.attack("Lorem Ipsum");

	for (size_t i = 0; i < 5; i++)
	{
		clap.beRepaired(20);
	}
	for (size_t i = 0; i < 100; i++)
	{
		clap.takeDamage(12);
	}


	// for (size_t i = 0; i < 6; i++)
	// {
	// 	clap.takeDamage(i + 1);
	// 	clap.beRepaired(i);
	// }


	// clap.getAttackDamage();

	// clap.beRepaired(100);
	ClapTrap b = clap;
}