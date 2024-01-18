/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:57:27 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/18 14:31:44 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
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


void	exec_presidential_form( void )
{

}

int main(void)
{
	display_big_line("CONSTRUCTOR");
	{
		ShrubberyCreationForm forma;
		RobotomyRequestForm	formb;
		PresidentialPardonForm	formc;

		ShrubberyCreationForm form1("ShrubberyFormulaire");
		RobotomyRequestForm	form2("RobotomyFormulaire");
		PresidentialPardonForm	form3("PresidentialFormulaire");
		Bureaucrat	random("random", 150);
	}
	display_big_line("INVALID REGISTER");
	{
		ShrubberyCreationForm form("Formulaire");
		Bureaucrat random("Steven", 146);
		try
		{
			random.signForm(form);
		}
		catch(const std::exception& e)
		{
			display_err(e);
		}
		try
		{
			random.executeForm(form);
		}
		catch(const std::exception& e)
		{
			display_err(e);
		}
		for (size_t i = 0; i < 4; i++)
		{
			std::cout << random;
			random.increaseGrade();
		}
		try
		{
			random.signForm(form);
		}
		catch(const std::exception& e)
		{
			display_err(e);
		}
		try
		{
			random.executeForm(form);
		}
		catch(const std::exception& e)
		{
			display_err(e);
		}
	}
	display_big_line("GENIUS");
	{
		ShrubberyCreationForm form("DestGenius");
		Bureaucrat random("J2K", 10);
		random.signForm(form);
		random.executeForm(form);
	}
}
