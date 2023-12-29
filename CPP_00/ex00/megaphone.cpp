/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 08:51:15 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/28 09:35:50 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	display_upper(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		str[i] = std::toupper(str[i]);
		std::cout << str[i];
	}
}



int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
		display_upper(argv[i]);
	std::cout << std::endl;
	return (0);
}
