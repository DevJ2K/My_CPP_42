/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:10:19 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/22 23:29:48 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
private:
	T*	_array;
	int	_size;
public:
	Array<T>();
	Array<T>( unsigned int n );
	Array<T>( Array<T> const & src );
	~Array<T>();

	Array<T>	&operator=( Array<T> const & rhs );

	class IndexOutOfRangeException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	}

	int	size( void ) const;
};

Array::Array(/* args */)
{
}

Array::~Array()
{
}

#endif
