/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:51:28 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/30 18:42:38 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::_debug( void ) const
{
	std::cout << GREENHB << "[ DEBUG ]" << RESET
	<< GREEN
	<< " : I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !"
	<< RESET << std::endl;
}
void	Harl::_info( void ) const
{
	std::cout << CYANHB << "[ INFO ]" << RESET
	<< CYAN
	<< " : I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !"
	<< RESET << std::endl;
}
void	Harl::_warning( void ) const
{
	std::cout << YELLOWHB << "[ WARNING ]" << RESET
	<< YELLOW
	<< " : I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
	<< RESET << std::endl;
}
void	Harl::_error( void ) const
{
	std::cout << REDHB << "[ ERROR ]" << RESET
	<< RED
	<< " : This is unacceptable ! I want to speak to the manager now."
	<< RESET << std::endl;
}

void	Harl::complain( std::string level )
{
	void	(Harl::*level_function[4])(void) const = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string all_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	bool level_find = false;
	for (size_t i = 0; i < 4; i++)
	{
		if (all_level[i].compare(level.c_str()) == 0)
		{
			(this->*level_function[i])();
			level_find = true;
			break;
		}
	}
	if (level_find == false)
	{
		std::cout << MAGHB << "[ ??? ]" << RESET
	<< MAG << " : Aucun niveau de debug trouve !" << RESET << std::endl;
	}
}
