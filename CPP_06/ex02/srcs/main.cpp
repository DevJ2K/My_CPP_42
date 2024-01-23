/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:16:14 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 17:30:20 by tajavon          ###   ########.fr       */
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
	try
	{
		A* a_ = dynamic_cast<A *>(p);
		(void)a_;
		// a_->displayType();
		std::cout << BHGREEN << "I'm a class [A]" << RESET << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << BHRED << "I'm not a class [A]" << std::endl;
		std::cerr << e.what() << '\n';
	}
	try
	{
		B* b_ = dynamic_cast<B *>(p);
		(void)b_;
		// b_->displayType();
		std::cout << BHGREEN << "I'm a class [B]" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << BHRED << "I'm not a class [B]" << std::endl;
		std::cerr << e.what() << '\n';
	}
	try
	{
		C* c_ = dynamic_cast<C *>(p);
		(void)c_;
		// c_->displayType();
		std::cout << BHGREEN << "I'm a class [C]" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << BHRED << "I'm not a class [C]" << std::endl;
		std::cerr << e.what() << '\n';
	}
}

void identify(Base &p)
{
	try
	{
		A a_ = dynamic_cast<A &>(p);
		a_.displayType();
		std::cout << BHGREEN << "I'm a class [A]" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << BHRED << "I'm not a class [A]" << std::endl;
		std::cerr << e.what() << '\n';
	}
	try
	{
		B b_ = dynamic_cast<B &>(p);
		b_.displayType();
		std::cout << BHGREEN << "I'm a class [B]" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << BHRED << "I'm not a class [B]" << std::endl;
		std::cerr << e.what() << '\n';
	}
	try
	{
		C c_ = dynamic_cast<C &>(p);
		c_.displayType();
		std::cout << BHGREEN << "I'm a class [C]" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << BHRED << "I'm not a class [C]" << std::endl;
		std::cerr << e.what() << '\n';
	}
}

int	main(void)
{
	Base* base_random = generate();
	base_random->displayType();
	identify(base_random);
	// identify(*base_random);

	delete base_random;
}
