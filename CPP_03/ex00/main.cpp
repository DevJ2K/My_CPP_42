/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:00:49 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 09:27:14 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap clap("J2K");

	clap.attack("Lorem Ipsum");

	for (size_t i = 0; i < 5; i++)
		clap.beRepaired(20);

	for (size_t i = 0; i < 11; i++)
		clap.takeDamage(12);
	clap.attack("Someone");
	clap.beRepaired(100);
}