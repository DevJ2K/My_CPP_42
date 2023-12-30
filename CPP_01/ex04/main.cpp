/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:46:04 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/30 17:47:44 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	display_error_file( std::string filename, int status )
{
	std::cout << BHRED << "Error: " << RESET
	<< RED << "Failed to open the file : " << RESET << BHRED;
	if (status == -1)
		std::cout << filename;
	else if (status == -2)
		std::cout << filename << ".replace";
	std::cout << RESET << std::endl;
	return (1);
}

int	main(int argc, char **argv)
{
	int	status = 0;

	if (argc != 4)
	{
		std::cout << BHRED << "The number of arguments is invalid ! " << RESET << std::endl
		<< "Format : " << BHWHITE << "./replace " << RESET << BHMAG << "<filename> " << RESET
		<< BHYELLOW << "<occurence_to_replace> <replace_by>" << RESET << std::endl;
		return (1);
	}
	status = replace(argv[1], argv[2], argv[3]);
	if (status < 0)
		return (display_error_file(argv[1], status));

	std::cout << BHGREEN << "Success: " << RESET
	<< BHCYAN << argv[1] << ".replace" << RESET
	<< BHWHITE << " was created successfully !" << RESET << std::endl;
	return (0);
}
