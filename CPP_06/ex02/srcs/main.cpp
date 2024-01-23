/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:16:14 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 23:12:43 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <time.h>
#include <iostream>
#include "Colors.hpp"
#include <cstdlib>
#include <exception>

static void display_sub_line(std::string title)
{
	size_t line_size = 50;

	std::cout << std::endl;

	for (size_t i = 0; i < (line_size - title.length()) / 2; i++)
		std::cout << BHWHITE << "=" << RESET;

	std::cout << BHCYAN << title << RESET;

	for (size_t i = 0; i < (line_size - title.length()) / 2; i++)
		std::cout << BHWHITE << "=" << RESET;

	std::cout << std::endl;
	std::cout << std::endl;
	return;
}

Base* generate(void)
{
	std::srand(time(NULL));

	switch (std::rand() % 3 + 1)
	{
	case 1:
		return (new A());
		break;

	case 2:
		return (new B());
		break;

	case 3:
		return (new C());
		break;

	default:
		std::cout << BHRED << "ERROR RANDOM !" << RESET << std::endl;
		return (NULL);
		break;
	}
}

void identify(Base *p)
{

	if (!p)
	{
		std::cout << BHRED << "Cannot identify a null pointer." << RESET << std::endl;
		return ;
	}
	A* a_ = dynamic_cast<A *>(p);
	B* b_ = dynamic_cast<B *>(p);
	C* c_ = dynamic_cast<C *>(p);
	if (a_)
		a_->displayType();
	else
		std::cout << BHRED << "I'm not a class [A]" << std::endl;
	if (b_)
		b_->displayType();
	else
		std::cout << BHRED << "I'm not a class [B]" << std::endl;
	if (c_)
		c_->displayType();
	else
		std::cout << BHRED << "I'm not a class [C]" << std::endl;

}

void identify(Base &p)
{
	try
	{
		A a_ = dynamic_cast<A &>(p);
		a_.displayType();
	}
	catch(const std::exception& e)
	{
		std::cout << BHRED << "I'm not a class [A]" << std::endl;
	}
	try
	{
		B b_ = dynamic_cast<B &>(p);
		b_.displayType();
	}
	catch(const std::exception& e)
	{
		std::cout << BHRED << "I'm not a class [B]" << std::endl;
	}
	try
	{
		C c_ = dynamic_cast<C &>(p);
		c_.displayType();
	}
	catch(const std::exception& e)
	{
		std::cout << BHRED << "I'm not a class [C]" << std::endl;
	}
}

int	main(void)
{

	for (size_t i = 0; i < 5; i++)
	{
		display_sub_line("Generate Random ");
		Base* base_random = generate();
		std::cout << BHWHITE << "Find identity by pointer." << std::endl;
		identify(base_random);
		std::cout << BHWHITE << "Find identity by reference." << std::endl;
		identify(*base_random);
		delete base_random;
	}


}
