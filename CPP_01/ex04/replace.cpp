/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:57:19 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/30 17:45:56 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	create_replace_file(char *filename, std::string content )
{
	std::string new_file = "";

	new_file.append(filename);
	new_file.append(".replace");
	std::ofstream replace_file(new_file.c_str());
	if (replace_file.is_open() == false)
		return (-1);
	replace_file << content;
	replace_file.close();
	return (0);
}

int	find_in_string(const char *str, char *to_find)
{
	int i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

int	replace( char *filename, char *to_replace, char *replace_by )
{
	std::ifstream init_file(filename);

	// Si l'ouverture du fichier a echoue
	if (init_file.is_open() == false)
		return (-1);

	// Pour recuperer le contenu du fichier
	std::string buffer;
	std::string	filecontent;
	while (std::getline(init_file, buffer))
	{
		filecontent.append(buffer);
		if (init_file.eof() == false)
			filecontent.append("\n");
	}

	// Replace
	size_t i = 0;
	while (filecontent.c_str()[i])
	{
		if (find_in_string(&filecontent.c_str()[i], to_replace))
		{
			int	j = 0;
			while (to_replace[j])
				j++;
			if (j == 0)
			{
				i++;
				continue;
			}
			filecontent.erase(i, j);

			filecontent.insert(i, replace_by);

			int	k = 0;
			while (replace_by[k])
				k++;
			i += k;
		}
		else
			i++;
	}
	init_file.close();
	if (create_replace_file(filename, filecontent) == -1)
		return (-2);
	return (0);
}
