/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:48:38 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/25 16:25:34 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span() : _maxSize(1024)
{
}

Span::Span( unsigned int N ) : _maxSize(N)
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
	this->_list = rhs.getList();
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

unsigned int	Span::getMaxSize( void ) const
{
	return (this->_maxSize);
}

std::size_t	Span::getNbElements( void ) const
{
	return (this->_list.size());
}

std::list<int>	Span::getList( void ) const
{
	return (this->_list);
}

void	Span::addNumbers( std::list<int>::const_iterator it_begin, std::list<int>::const_iterator it_end )
{
	for ( std::list<int>::const_iterator it = it_begin; it != it_end; it++)
		this->addNumber(*it);
}

void	Span::addNumber( int nb )
{
	if (this->getNbElements() >= this->_maxSize)
		throw TooManyNumbersException();
	this->_list.push_back(nb);
}

int	Span::shortestSpan( void ) const
{
	if (this->getNbElements() <= 1)
		throw NotEnoughNumbersException();
	int	min_span = this->longestSpan();
	for (unsigned int i = 0; i < this->getNbElements(); i++)
	{
		for (unsigned int j = 0; j < this->getNbElements(); j++)
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

// Source : https://cplusplus.com/reference/algorithm/max_element/
// Source : https://cplusplus.com/reference/algorithm/min_element/
int	Span::longestSpan( void ) const
{
	if (this->getNbElements() <= 1)
		throw NotEnoughNumbersException();
	// int	max = (*this)[0];
	// int	min = (*this)[0];

	// for (unsigned int i = 0; i < this->getNbElements(); i++)
	// {
	// 	if ((*this)[i] > max)
	// 		max = (*this)[i];
	// 	if ((*this)[i] < min)
	// 		min = (*this)[i];
	// }
	int min = *std::min_element(this->_list.begin(), this->_list.end());
	int max = *std::max_element(this->_list.begin(), this->_list.end());
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
