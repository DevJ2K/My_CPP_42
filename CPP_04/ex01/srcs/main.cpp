/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:35:26 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/05 10:12:50 by tajavon          ###   ########.fr       */
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

void	ideas_dog(Dog *dog, int status)
{
	if (status == 0)
	{
		for (int i = 0; i < dog->getBrain()->getNbIdeas(); i++)
		{
			dog->getBrain()->setIdeas(i, "Je suis un chien avec une idee !");
		}
	}
	if (status == 1)
	{
		for (int i = 0; i < dog->getBrain()->getNbIdeas(); i++)
		{
			std::cout << BYELLOW << dog->getBrain()->getIdeas(i) << RESET << std::endl;
		}

	}
}
void	ideas_cat(Cat *cat, int status)
{
	if (status == 0)
	{
		for (int i = 0; i < cat->getBrain()->getNbIdeas(); i++)
		{
			cat->getBrain()->setIdeas(i, "I have an idea, bc I'm a cat !!");
		}
	}
	if (status == 1)
	{
		for (int i = 0; i < cat->getBrain()->getNbIdeas(); i++)
		{
			std::cout << BYELLOW << cat->getBrain()->getIdeas(i) << RESET << std::endl;
		}

	}
}

int main()
{
	size_t	nb_animaux = 5;
	Animal	*le_zoo[nb_animaux];

	display_big_line("FILL ZOO");
	for (size_t i = 0; i < nb_animaux; i++)
	{
		if (i % 2 == 0)
		{
			Dog* newdog = new Dog();
			ideas_dog(newdog, 0);
			le_zoo[i] = newdog;
		}
		else
		{
			Cat* newcat = new Cat();
			ideas_cat(newcat, 0);
			le_zoo[i] = newcat;
		}
	}
	display_big_line("DOG IDEAS");
	ideas_dog((Dog *)le_zoo[0], 1);

	display_big_line("CAT IDEAS");
	ideas_cat((Cat *)le_zoo[1], 1);

	display_big_line("DEEP COPY");
	{
		Dog basic;
		ideas_dog(&basic, 0);
		ideas_dog(&basic, 1);
		{
			Dog tmp = basic;
			ideas_dog(&tmp, 1);
		}
		ideas_dog(&basic, 1);
	}

	display_big_line("DELETE ZOO");
	for (size_t i = 0; i < nb_animaux; i++)
		delete le_zoo[i];

	display_big_line("END");
	return 0;
}
