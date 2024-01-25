/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:47:37 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/25 16:26:26 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <stdexcept>
#include <list>

// Source : https://cplusplus.com/reference/algorithm/find/
template <typename T>
typename T::const_iterator	easyfind( T lst, int n )
{
	typename T::const_iterator iterator = std::find(lst.begin(), lst.end(), n);
	if (iterator != lst.end())
		return (iterator);
	throw std::invalid_argument("Element not found");
}

#endif
