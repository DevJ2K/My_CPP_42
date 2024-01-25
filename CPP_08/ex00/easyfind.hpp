/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:47:37 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/25 16:09:35 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <stdexcept>
#include <list>

template <typename T>
typename T::const_iterator	easyfind( T lst, int n )
{
	typename T::const_iterator iterator = std::find(lst.begin(), lst.end(), n);
	if (iterator != lst.end())
		return (iterator);
	// for (typename T::const_iterator it = lst.begin(); it != lst.end(); it++)
	// {
	// 	if (*it == n)
	// 		return (it);
	// }
	throw std::invalid_argument("Element not found");
}

#endif
