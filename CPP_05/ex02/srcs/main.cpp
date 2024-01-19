/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:57:27 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/19 09:40:16 by tajavon          ###   ########.fr       */
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

static void display_sub_line(std::string title)
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

static void display_big_line(std::string title)
{
	size_t line_size = 60;

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

void test_form(AForm *form)
{
	display_sub_line("INVALID GRADE");
	{
		Bureaucrat stupid("Stupid", 150);
		std::cout << stupid;
		stupid.signForm(*form);
		stupid.executeForm(*form);
	}
	display_sub_line("CAN EXECUTE");
	{
		Bureaucrat genius("Genius", 1);
		std::cout << genius;
		std::cout << *form;
		genius.signForm(*form);
		std::cout << *form;
		genius.executeForm(*form);
	}
}

int main(void)
{
	display_sub_line("CONSTRUCTOR");
	{
		ShrubberyCreationForm forma;
		RobotomyRequestForm formb;
		PresidentialPardonForm formc;

		ShrubberyCreationForm form1("ShrubberyFormulaire");
		RobotomyRequestForm form2("RobotomyFormulaire");
		PresidentialPardonForm form3("PresidentialFormulaire");
		Bureaucrat random("random", 150);
	}
	display_big_line("");
	{
		display_sub_line("SHRUBBERY CREATION");
		ShrubberyCreationForm form1("ShrubberyFormulaire");
		test_form(&form1);
	}
	display_big_line("");
	{
		display_sub_line("ROBOTOMY REQUEST");
		RobotomyRequestForm form2("RobotomyFormulaire");
		test_form(&form2);
	}
	display_big_line("");
	{
		display_sub_line("PRESIDENTIAL PARDON");
		PresidentialPardonForm form3("PresidentialFormulaire");
		test_form(&form3);
	}
}
