/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:35:26 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 21:35:27 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Colors.hpp"
#include <iostream>

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

// static void	display_type( std::string type)
// {
// 	std::cout << BWHITE << "I'm a " << RESET << BHMAG << type << RESET << std::endl;
// 	return ;
// }

int main()
{
	size_t	nb_animaux = 6;
	Animal	*le_zoo[nb_animaux];

	display_big_line("FILL ZOO");
	for (size_t i = 0; i < nb_animaux; i++)
	{
		if (i % 2 == 0)
			le_zoo[i] = new Dog();
		else
			le_zoo[i] = new Cat();
	}

	Dog basic;
	{
		Dog tmp = basic;
	}

	display_big_line("DELETE ZOO");
	for (size_t i = 0; i < nb_animaux; i++)
		delete le_zoo[i];

	display_big_line("END");
	return 0;
}
