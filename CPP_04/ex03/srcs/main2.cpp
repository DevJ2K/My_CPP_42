/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:42:43 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/05 16:06:17 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Colors.hpp>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "AMateria.hpp"

static void	display_big_line( std::string title )
{
	size_t line_size = 30;

	std::cout << std::endl;

	for (size_t i = 0; i < (line_size - title.length()) / 2; i++)
		std::cout << BHWHITE << "=" << RESET;

	std::cout << BHCYAN << title << RESET;

	for (size_t i = 0; i < (line_size - title.length()) / 2; i++)
		std::cout << BHWHITE << "=" << RESET;

	std::cout << std::endl;
	std::cout << std::endl;
	return ;
}

int	main(void)
{
	display_big_line("CREATE MATERIA SOURCE");
	MateriaSource	*all_materia = new MateriaSource();
	all_materia->displayLearnMateria();

	Ice *ice1 = new Ice();
	Cure *cure1 = new Cure();

	all_materia->learnMateria(ice1);
	all_materia->learnMateria(cure1);

	all_materia->displayLearnMateria();

	display_big_line("ERROR MATERIA SOURCE");
	all_materia->learnMateria(0);
	all_materia->learnMateria(new Ice());
	all_materia->learnMateria(new Cure());
	all_materia->learnMateria(new Ice());
	{
		AMateria *tmp = all_materia->createMateria("lave");
		tmp = all_materia->createMateria("ice");
		if (tmp)
			delete tmp;
	}
	all_materia->displayLearnMateria();

	display_big_line("CREATE CHARACTER");
	Character	*j2k = new Character("J2K");


	j2k->displayInventory();
	j2k->equip(all_materia->createMateria("ice"));
	j2k->equip(all_materia->createMateria("cure"));
	j2k->equip(all_materia->createMateria("ice"));
	j2k->equip(all_materia->createMateria("cure"));
	j2k->displayInventory();

	display_big_line("ERROR CHARACTER");
	Ice* ice2 = new Ice();
	j2k->equip(ice2);
	j2k->unequip(-1);
	j2k->unequip(5);
	j2k->displayInventory();
	delete ice2;
	delete j2k;
	delete all_materia;

	display_big_line("EQUIP AND UNEQUIP ALL");
	Character	*player = new Character("player");
	player->displayInventory();
	Ice* i1 = new Ice();
	Ice* i2 = new Ice();
	Ice* i3 = new Ice();
	Ice* i4 = new Ice();

	player->equip(i1);
	player->equip(i2);
	player->equip(i3);
	player->equip(i4);
	player->displayInventory();
	for (size_t i = 0; i < 4; i++)
		player->unequip(i);
	player->displayInventory();

	delete i1;
	delete i2;
	delete i3;
	delete i4;

	delete player;

}