/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:44:09 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/02 12:32:34 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>


int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}

// int	main( void )
// {
// 	Fixed a(10);
// 	Fixed b(20);
// 	std::cout << BHWHITE << "a=" << a << " est " << RESET << BHYELLOW
// 	<< (a > b ? "superieur" : "inferieur") << RESET << BHWHITE
// 	<< " a b="<< b << RESET << std::endl;


// 	std::cout << BHWHITE << "a=" << a << " est " << RESET << BHYELLOW
// 	<< (a == b ? "egal" : "different") << RESET << BHWHITE
// 	<< " de b="<< b << RESET << std::endl;


// 	b = Fixed (10);
// 	std::cout << BHWHITE << "a=" << a << " est " << RESET << BHYELLOW
// 	<< (a == b ? "egal" : "different") << RESET << BHWHITE
// 	<< " a b="<< b << RESET << std::endl;

// 	a = Fixed(40);
// 	b = Fixed(50);
// 	std::cout << BHWHITE << "Le max entre a=40 et b=50 est " << RESET << BHMAG << Fixed::max(a, b) << RESET << std::endl;
// }
