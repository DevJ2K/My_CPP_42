/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:55:02 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 16:42:18 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include "Colors.hpp"

static void display_sub_line(std::string title)
{
	size_t line_size = 50;

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

int	main(void)
{

	display_sub_line("INIT DATA");
	Data	*data = new Data(14, "June", 2005);
	uintptr_t	ptr = Serializer::serialize(data);
	std::cout << "UINTPTR_T : " << ptr << std::endl;

	display_sub_line("REINTERPRET (UNITPTR_T) to (DATA *)");
	Data	*data2;
	data2 = Data::deserialize(ptr);
	data2->displayData();

	delete data;
}
