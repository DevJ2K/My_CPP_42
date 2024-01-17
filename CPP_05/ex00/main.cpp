/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:57:27 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/17 14:52:48 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
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

// int	main( int argc, char **argv )
// {
// 	int	nb;

// 	if (argc != 3)
// 		return (0);

// 	std::istringstream	iss(argv[2]);
// 	iss >> nb;
// 	Bureaucrat bureaucrat(argv[1], nb);
// 	std::cout << bureaucrat;
// 	return (0);
// }

void display_err(const std::exception &e)
{
	std::cerr << BHRED << "An error was catch: " << RESET BRED << e.what() << RESET << std::endl;
}

int main(void)
{
	display_big_line("INIT ERROR");
	{
		try
		{
			Bureaucrat err1("Err1", -2);
		}
		catch (const std::exception &e)
		{
			display_err(e);
		}
		try
		{
			Bureaucrat err1("Err2", 250);
		}
		catch (const std::exception &e)
		{
			display_err(e);
		}
	}
	display_big_line("INCREMENT ERROR");
	{
		Bureaucrat genius("Genius", 3);
		try
		{
			for (size_t i = 0; i < 1000; i++)
			{
				std::cout << genius;
				genius.increaseGrade();
			}
		}
		catch (const std::exception &e)
		{
			display_err(e);
		}
	}
	display_big_line("DECREMENT ERROR");
	{
		Bureaucrat stupid("Stupid", 148);
		try
		{
			for (size_t i = 0; i < 1000; i++)
			{
				std::cout << stupid;
				stupid.decreaseGrade();
			}
		}
		catch (const std::exception &e)
		{
			display_err(e);
		}
	}
	display_big_line("DECREMENT ERROR");
	{
		Bureaucrat good("J2K", 5);
		for (size_t i = 0; i < 2; i++)
		{
			std::cout << good;
			good.decreaseGrade();
		}
		for (size_t i = 0; i < 2; i++)
		{
			std::cout << good;
			good.increaseGrade();
		}
	}
}
