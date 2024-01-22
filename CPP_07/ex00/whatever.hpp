/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:27:56 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/22 22:31:36 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void	swap( T &a, T &b )
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T const &	min(T const & a, T const & b )
{
	return (a < b ? a : b);
}

template <typename T>
T const &	max(T const & a, T const & b )
{
	return (a > b ? a : b);
}
