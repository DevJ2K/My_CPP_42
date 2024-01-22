/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:36:57 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/22 18:14:17 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	// convertie moi argv[1] en std::string
	std::string str = argv[1];
	ScalarConverter::convert(str);
}
