/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:44:09 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/02 11:59:15 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << "before set A: " << a.getRawBits() << std::endl;
	std::cout << "before set B: " << b.getRawBits() << std::endl;
	std::cout << "before set C: " << c.getRawBits() << std::endl;

	a.setRawBits(42);
	b.setRawBits(84);
	c.setRawBits(128);

	std::cout << "after set A: " << a.getRawBits() << std::endl;
	std::cout << "after set B: " << b.getRawBits() << std::endl;
	std::cout << "after set C: " << c.getRawBits() << std::endl;

	return (0);
}
