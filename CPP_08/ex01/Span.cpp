/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:48:38 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/24 17:13:08 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

Span::Span()
{
}

Span::Span( unsigned int N ) : _nbElements(0), _size(N)
{
}
Span::Span( Span const & src )
{
	*this = src;
}

Span::~Span()
{
}

Span	&Span::operator=( Span const & rhs )
{
	this->_nbElements = rhs.getNbElements();
	this->_size = rhs.getSize();
	for (unsigned int i = 0; i < rhs.getNbElements(); i++)
		this->addNumber(rhs[i]);
	return (*this);
}

int		Span::operator[]( unsigned int index ) const
{
	if (index < 0 || index >= this->getNbElements())
		throw OutOfRangeException();

	std::list<int>::const_iterator it = this->_list.begin();
	for (unsigned int i = 0; i < index; i++)
		it++;
	return (*it);
}

unsigned int	Span::getSize( void ) const
{
	return (this->_size);
}
unsigned int	Span::getNbElements( void ) const
{
	return (this->_nbElements);
}

void	Span::addNumber( int nb )
{
	if (this->_nbElements >= this->_size)
		throw TooManyNumbersException();
	this->_list.push_back(nb);
	this->_nbElements++;
}

int	Span::shortestSpan( void ) const
{
	if (this->_nbElements <= 1)
		throw NotEnoughNumbersException();
	int	min_span = this->longestSpan();
	for (unsigned int i = 0; i < this->_nbElements; i++)
	{
		for (unsigned int j = 0; j < this->_nbElements; j++)
		{
			if (i != j)
			{
				if ((*this)[i] - (*this)[j] < min_span && (*this)[i] - (*this)[j] >= 0)
					min_span = (*this)[i] - (*this)[j];
			}
		}
	}
	return (min_span);
}
int	Span::longestSpan( void ) const
{
	if (this->_nbElements <= 1)
		throw NotEnoughNumbersException();
	int	max = (*this)[0];
	int	min = (*this)[0];
	for (unsigned int i = 0; i < this->_nbElements; i++)
	{
		if ((*this)[i] > max)
			max = (*this)[i];
		if ((*this)[i] < min)
			min = (*this)[i];
	}
	return (max - min);
}

const char	*Span::TooManyNumbersException::what() const throw()
{
	return ("Too Many Numbers");
}

const char	*Span::OutOfRangeException::what() const throw()
{
	return ("Out Of Range");
}

const char	*Span::NotEnoughNumbersException::what() const throw()
{
	return ("Not Enough Numbers");
}
