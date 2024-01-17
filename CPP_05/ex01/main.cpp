/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:57:27 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/17 17:19:24 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Colors.hpp"
#include <sstream>
#include <istream>

static void display_big_line(std::string title)
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
	return;
}

void display_err(const std::exception &e)
{
	std::cerr << BHRED << "An error was catch: " << RESET BRED << e.what() << RESET << std::endl;
}

int main(void)
{
	display_big_line("CONSTRUCTOR");
	{
		Form defaultConstructor;
		Form basic("Formulaire", 130, 100);
		Form copy(basic);
		defaultConstructor = basic;
	}
	display_big_line("GRADE TOO HIGH ERROR");
	{
		try
		{
			Form basic("ERR", 0, 0);
		}
		catch(const std::exception& e)
		{
			display_err(e);
		}

	}
	display_big_line("GRADE TOO LOW ERROR");
	{
		try
		{
			Form basic("ERR", 151, 151);
		}
		catch(const std::exception& e)
		{
			display_err(e);
		}

	}
	display_big_line("GENIUS FORM");
	{
		Bureaucrat genius("Genius", 5);
		Form geniusForm("FormForGenius", 25, 10);
		genius.signForm(geniusForm);
		try
		{
			genius.signForm(geniusForm);
		}
		catch(const std::exception& e)
		{
			display_err(e);
		}

	}
	display_big_line("TOO DUMB FORM");
	{
		Bureaucrat stupid("Stupid", 145);
		Form geniusForm("FormForGenius", 25, 10);
		try
		{
			stupid.signForm(geniusForm);
		}
		catch(const std::exception& e)
		{
			display_err(e);
		}

	}
}
