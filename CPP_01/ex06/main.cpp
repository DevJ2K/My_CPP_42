/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:51:24 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/30 18:48:40 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cout << BRED << "Bad number of arguments." << RESET << std::endl;
		return (1);
	}
	Harl varHarl;
	varHarl.complain(argv[1]);
	return (0);
}
