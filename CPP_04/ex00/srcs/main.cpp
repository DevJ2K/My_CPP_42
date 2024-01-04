/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:35:26 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 14:54:44 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Colors.hpp"
#include <iostream>

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	// const WrongAnimal* i = new WrongCat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound();
// 	j->makeSound();
// 	meta->makeSound();

// 	delete meta;
// 	delete j;
// 	delete i;
// 	return 0;
// }

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

static void	display_type( std::string type)
{
	std::cout << BWHITE << "I'm a " << RESET << BHMAG << type << RESET << std::endl;
	return ;
}

int main()
{
	display_big_line("ANIMAL");
	const Animal* meta = new Animal();
	display_type(meta->getType());
	meta->makeSound();
	delete meta;

	display_big_line("DOG");
	const Animal* dog = new Dog();
	display_type(dog->getType());
	dog->makeSound();
	delete dog;

	display_big_line("CAT");
	const Animal* cat = new Cat();
	display_type(cat->getType());
	cat->makeSound();
	delete cat;


	display_big_line("WRONGCAT");
	const WrongAnimal* wrongCat = new WrongCat();
	display_type(wrongCat->getType());
	wrongCat->makeSound();
	delete wrongCat;

	display_big_line("END");
	return 0;
}
