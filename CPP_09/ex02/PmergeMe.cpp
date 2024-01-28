/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:53:41 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/28 16:04:04 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Colors.hpp"
#include <chrono>
#include <sstream>
#include <iostream>
#include <algorithm>

PmergeMe::PmergeMe() : _list(0), _vector(0)
{
}

PmergeMe::PmergeMe( PmergeMe const & src )
{
	*this = src;
}

static bool	only_digits( char *str )
{
	for (size_t i = 0; str[i]; i++)
	{
		if (std::isdigit(str[i]) == 0)
			return (false);
	}
	return (true);
}

static void	display_big_line( std::string colors, std::string text )
{
	size_t line_size = 20 - (text.length() / 2);
	for (size_t i = 0; i < line_size; i++)
		std::cout << BHWHITE "=" RESET;

	std::cout << colors << text << RESET;

	for (size_t i = 0; i < line_size; i++)
		std::cout << BHWHITE "=" RESET;
	std::cout << std::endl << std::endl;
}

PmergeMe::PmergeMe( int nb_numbers, char **numbers_args )
{
	for (int i = 0; i < nb_numbers; i++)
	{
		if (only_digits(numbers_args[i]) == 0)
			throw NotAnUintException();
		std::istringstream	iss(numbers_args[i]);
		unsigned int	nb;
		iss >> nb;
		if (!iss.eof() || iss.fail())
			throw NotAnUintException();
		// if (std::find(this->_list.begin(), this->_list.end(), nb) != this->_list.end())
		// 	throw DuplicateException();
		// if (std::find(this->_vector.begin(), this->_vector.end(), nb) != this->_vector.end())
		// 	throw DuplicateException();
		this->_list.push_back(nb);
		this->_vector.push_back(nb);
	}
	display_big_line(BHRED, "Before");
	displayBothLists();
	display_big_line(BHGREEN, "After");
	sortedContainers();
	displayBothLists();
	display_big_line(BHCYAN, "Time To Process");
	displayTimeToSorted();
}

void	PmergeMe::displayBothLists( void ) const
{
	std::cout << BHWHITE "Is Sorted : "
	<< (std::is_sorted(this->_list.begin(), this->_list.end()) ? (BHGREEN "YES") : (BHRED "NO"));
	std::cout << RESET BHWHITE " : " RESET;

	std::cout << BHYELLOW "std::list" RESET BHWHITE "<unsigned int>   [ " << RESET;
	for (std::list<unsigned int>::const_iterator it = this->_list.begin();
		it != this->_list.end();
		it++)
	{
		std::cout << BHYELLOW << *it << " " << RESET;
	}
	std::cout << BHWHITE << "[" << RESET << std::endl;

	std::cout << BHWHITE "Is Sorted : "
	<< (std::is_sorted(this->_vector.begin(), this->_vector.end()) ? (BHGREEN "YES") : (BHRED "NO"));
	std::cout << RESET BHWHITE " : " RESET;

	std::cout << BHMAG "std::vector" RESET BHWHITE "<unsigned int> [ " << RESET;
	for (std::vector<unsigned int>::const_iterator it = this->_vector.begin();
		it != this->_vector.end();
		it++)
	{
		std::cout << BHMAG << *it << " " << RESET;
	}
	std::cout << BHWHITE << "[" << RESET << std::endl << std::endl;
}

void	PmergeMe::displayTimeToSorted( void ) const
{
	std::chrono::microseconds duration_msList = std::chrono::duration_cast<std::chrono::microseconds>
												(this->_endTimeList - this->_startTimeList);

	std::chrono::microseconds duration_msVector = std::chrono::duration_cast<std::chrono::microseconds>
												(this->_endTimeVector - this->_startTimeVector);

	long long msList = duration_msList.count();
	long long msVector = duration_msVector.count();

	std::cout << BHWHITE "Time to process a range of " RESET BHYELLOW
	<< this->_list.size() << RESET BHWHITE " elements with " RESET BHYELLOW
	"std::list" RESET BHWHITE "<unsigned int>   : " RESET <<
	(msList <= msVector ? BHGREEN : BHRED) << msList << " us" RESET << std::endl;

	std::cout << BHWHITE "Time to process a range of " RESET BHMAG
	<< this->_list.size() << RESET BHWHITE " elements with " RESET BHMAG
	"std::vector" RESET BHWHITE "<unsigned int> : " RESET <<
	(msVector <= msList ? BHGREEN : BHRED) << msVector << " us" RESET << std::endl;
}

void	PmergeMe::sortedContainers( void )
{

	this->_startTimeList = std::chrono::high_resolution_clock::now();
	this->_list = mergeSortContainers(this->_list);
	this->_endTimeList = std::chrono::high_resolution_clock::now();

	this->_startTimeVector = std::chrono::high_resolution_clock::now();
	this->_vector = mergeSortContainers(this->_vector);
	this->_endTimeVector = std::chrono::high_resolution_clock::now();
}

PmergeMe::~PmergeMe()
{
}

PmergeMe	&PmergeMe::operator=( PmergeMe const & rhs )
{
	this->_list = rhs.getList();
	this->_vector = rhs.getVector();
	return (*this);
}

std::list<unsigned int>		PmergeMe::getList( void ) const
{
	return (this->_list);
}
std::vector<unsigned int>	PmergeMe::getVector( void ) const
{
	return (this->_vector);
}

const char	*PmergeMe::DuplicateException::what() const throw()
{
	return ("Duplicate element found.");
}

const char	*PmergeMe::NotAnUintException::what() const throw()
{
	return ("Not An Unsigned Int.");
}
