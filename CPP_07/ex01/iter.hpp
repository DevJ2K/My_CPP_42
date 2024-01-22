/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:32:58 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/22 22:59:46 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

template <typename T, typename U>
void	iter(T *adress, int length, U (*func)(T))
{
	for (int i = 0; i < length; i++)
	{
		try
		{
			func(adress[i]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			break ;
		}
	}
}
