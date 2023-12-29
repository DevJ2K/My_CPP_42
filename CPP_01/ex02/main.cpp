/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:56:03 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/29 18:01:06 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include <string>
#include <iostream>
#include <iomanip>

/*REFERENCE
Def : C'est constant et c'est impossible de la changer. Ref != NULL
C'est comme un pointeur deferencer
*/
int	main(void)
{
	std::string	string_init = "HI THIS IS BRAIN"; // Init
	std::string	*stringPTR = &string_init; // Pointeur
	std::string	&stringREF = string_init; // Reference

	std::cout << BCYAN << std::setw(25) << "Adresse string memoire : " << &string_init << RESET << std::endl;
	std::cout << BGREEN << std::setw(25) << "Adresse stringPTR : " << stringPTR << RESET << std::endl;
	std::cout << BRED << std::setw(25) << "Adresse stringREF : " << &stringREF << RESET << std::endl;
	std::cout << std::endl;

	std::cout << BCYAN << std::setw(25) << "Valeur string memoire : " << string_init << RESET << std::endl;
	std::cout << BGREEN << std::setw(25) << "Valeur stringPTR : " << *stringPTR << RESET << std::endl;
	std::cout << BRED << std::setw(25) << "Valeur stringREF : " << stringREF << RESET << std::endl;
	std::cout << std::endl;
	return (0);
}
