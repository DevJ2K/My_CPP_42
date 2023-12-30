/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:46:04 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/30 16:02:37 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	display_error( std::string error )
{
	std::cout << BHRED << "Error: " << RESET
	<< RED << error << RESET << std::endl;
}

int	main(int argc, char **argv)
{
	int	status = 0;

	if (argc != 4)
	{
		std::cout << BHRED << "Le nombre d'arguments est invalide ! " << RESET << std::endl;
		std::cout << "Format : " << BHWHITE << "./replace " << RESET << BHMAG << "<filename> " << RESET;
		std::cout << BHYELLOW << "<occurence_to_replace> <replace_by>" << RESET << std::endl;
		return (status + 1);
	}
	status = replace(argv[1], argv[2], argv[3]);
	if (status == -1)
	{
		display_error("Failed to open the file.");
		return (1);
	}
	if (status == 0)
	{
		std::cout << BHGREEN << "Success: " << RESET
		<< BHCYAN << argv[1] << ".replace" << RESET
		<< BHWHITE << " was created successfully !" << RESET << std::endl;
		return (0);
	}
	(void)argv;
	return (0);
}
