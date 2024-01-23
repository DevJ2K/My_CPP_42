/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:10:19 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 10:15:17 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
private:
	T*				_array;
	unsigned int	_size;
public:
	Array<T>() : _array(NULL), _size(0)
	{

	};

	Array<T>( unsigned int n ) : _array(new T[n]), _size(n)
	{

	};


	Array<T>( Array<T> const & src ) : _array(new T[src.size()]), _size(src.size())
	{
		*this = src;
	};

	~Array<T>()
	{
		if (this->_array)
			delete [] this->_array;
	};

	Array<T>	&operator=( Array<T> const & rhs )
	{
		this->_size = rhs.size();
		for (unsigned int i = 0; i < this->_size; i++)
		{
			this->_array[i] = rhs[i];
		}
		return (*this);
	};

	T	&operator[]( unsigned int index ) const
	{
		if (index < 0 || index >= this->_size)
			throw IndexOutOfRangeException();
		return (this->_array[index]);
	}

	class IndexOutOfRangeException : public std::exception
	{
		public:
			virtual const char	*what() const throw()
			{
				return ("Index out of range");
			}
	};

	unsigned int	size( void ) const
	{
		return (this->_size);
	}
};

// std::ostream & operator<<(std::ostream & o, Array<T> const & rhs);

template <typename T>
bool	&operator!=(int nb, Array<T> const & rhs )
{
	return (nb != rhs);
}

#endif
