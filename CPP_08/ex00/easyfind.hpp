/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:47:37 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/24 14:46:16 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>
#include <map>
#include <list>

// class easyfind
// {
// public:
// 	easyfind(/* args */);
// };


template <typename T>
typename T::const_iterator	easyfind( T lst, int n )
{
	for (typename T::const_iterator it = lst.begin(); it != lst.end(); it++)
	{
		if (*it == n)
			return (it);
	}
	throw std::invalid_argument("Element not found");
}

#endif
