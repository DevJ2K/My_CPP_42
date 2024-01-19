/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:57:27 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/19 10:22:18 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
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

void display_err(const std::exception &e)
{
	std::cerr << BHRED << "An error was catch: " << RESET BRED << e.what() << RESET << std::endl;
}

int main(void)
{
	display_sub_line("CONSTRUCTOR");
	{
		Intern	randomIntern;
		AForm*	form1;
		AForm*	form2;
		AForm*	form3;
		AForm*	form4;

		form1 = randomIntern.makeForm("shrubbery creation", "ShrubberyFormulaire");
		form2 = randomIntern.makeForm("robotomy request", "RobotomyFormulaire");
		form3 = randomIntern.makeForm("presidential pardon", "PresidentialFormulaire");
		try
		{
			form4 = randomIntern.makeForm("Invalid", "PresidentialFormulaire");
		}
		catch(const std::exception& e)
		{
			display_err(e);
		}
		delete form1;
		delete form2;
		delete form3;
	}

}
