/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:10:19 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 10:50:28 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <iostream>
#include "Colors.hpp"

template <typename T>
class Array
{
private:
	T*				_array;
	unsigned int	_size;
public:
	Array<T>() : _array(NULL), _size(0)
	{
		std::cout << BGREEN << "Initialized empty array !" << RESET << std::endl;
	};

	Array<T>( unsigned int n ) : _array(new T[n]), _size(n)
	{
		std::cout << BHGREEN << "Initialized an array with " << (RESET BHCYAN) << n << " elements !" << RESET << std::endl;
	};


	Array<T>( Array<T> const & src ) : _array(new T[src.size()]), _size(src.size())
	{
		std::cout << BHYELLOW << "Initialized an array with an other array of " << (RESET BHCYAN) << src.size() << " elements !" << RESET << std::endl;
		*this = src;
	};

	~Array<T>()
	{
		std::cout << BHRED << "Destruction of an array of " << (RESET BHCYAN) << this->_size << " elements !" << RESET << std::endl;
		if (this->_array)
			delete [] this->_array;
	};

	Array<T>	&operator=( Array<T> const & rhs )
	{
		std::cout << BHYELLOW << "Assignation operator called !" << RESET << std::endl;
		if (this->_array != NULL)
			delete [] this->_array;
		this->_array = new T[rhs.size()];
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

	void	display_array( void ) const
	{
		std::cout << BHWHITE << "[";
		for (unsigned int i = 0; i < this->_size; i++)
		{
			std::cout << BHCYAN << " " << this->_array[i] << RESET;
			if (i < this->_size - 1)
				std::cout << BHWHITE << " -" << RESET;
		}
		std::cout << BHWHITE << "]" << std::endl;
	}
};

// std::ostream & operator<<(std::ostream & o, Array<T> const & rhs);

template <typename T>
bool	&operator!=(int nb, Array<T> const & rhs )
{
	return (nb != rhs);
}

#endif
