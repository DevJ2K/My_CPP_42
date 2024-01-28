/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:53:49 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/28 15:57:47 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <list>
#include <vector>
#include <exception>
#include <ctime>
#include <iostream>


class PmergeMe
{
private:
	std::list<unsigned int>		_list;
	std::vector<unsigned int>	_vector;

	typedef std::chrono::high_resolution_clock::time_point time_point;

	time_point	_startTimeList;
	time_point	_startTimeVector;

	time_point	_endTimeList;
	time_point	_endTimeVector;

	PmergeMe();
	PmergeMe( PmergeMe const & src );
public:
	PmergeMe( int nb_numbers, char **numbers_args );
	~PmergeMe();

	PmergeMe	&operator=( PmergeMe const & rhs );

	void	displayBothLists( void ) const;
	void	displayTimeToSorted( void ) const;
	void	sortedContainers( void );


	std::list<unsigned int>		getList( void ) const;
	std::vector<unsigned int>	getVector( void ) const;

	class DuplicateException : public std::exception
	{
	public:
		virtual const char	*what() const throw();
	};

	class NotAnUintException : public std::exception
	{
	public:
		virtual const char	*what() const throw();
	};

};

template <typename T>
T	mergeTwoArrays( T & list_one, T & list_two )
{
	T return_array;

	while (list_one.size() && list_two.size())
	{
		if ((*list_one.begin()) > (*list_two.begin()))
		{
			return_array.push_back((*list_two.begin()));
			list_two.pop_front();
		}
		else
		{
			return_array.push_back((*list_one.begin()));
			list_one.pop_front();
		}
	}
	while (list_one.size())
	{
		return_array.push_back((*list_one.begin()));
		list_one.pop_front();
	}
	while (list_two.size())
	{
		return_array.push_back((*list_two.begin()));
		list_two.pop_front();
	}
	return (return_array);
}

/* template <typename T>
void	vector_pop_front(std::vector<T> & param_vector )
{
	typename std::vector<T>::iterator it = param_vector.begin();
	it++;

	std::vector<T> copyVector;
	while (it != param_vector.end())
	{
		copyVector.push_back(*it);
		it++;
	}
	while (param_vector.size())
		param_vector.pop_back();

	it = copyVector.begin();
	while (it != copyVector.end())
	{
		param_vector.push_back(*it);
		it++;
	}
} */

template <typename T>
void	vector_pop_front(std::vector<T> & param_vector )
{
	typename std::vector<T>::iterator it = param_vector.begin();
	it++;

	std::vector<T> copyVector;
	while (it != param_vector.end())
	{
		copyVector.push_back(*it);
		it++;
	}
	param_vector = copyVector;
}

template <typename T>
std::vector<T>	mergeTwoArrays( std::vector<T> & list_one, std::vector<T> & list_two )
{
	std::vector<T> return_array;

	while (list_one.size() && list_two.size())
	{
		if ((*list_one.begin()) > (*list_two.begin()))
		{
			return_array.push_back((*list_two.begin()));
			vector_pop_front(list_two);
		}
		else
		{
			return_array.push_back((*list_one.begin()));
			vector_pop_front(list_one);
		}
	}
	while (list_one.size())
	{
		return_array.push_back((*list_one.begin()));
		vector_pop_front(list_one);
	}
	while (list_two.size())
	{
		return_array.push_back((*list_two.begin()));
		vector_pop_front(list_two);
	}
	return (return_array);
}

template <typename T>
T	mergeSortContainers( T & list )
{
	if (list.size() == 1)
		return (list);

	T array_one;
	T array_two;

	typename T::iterator it = list.begin();
	for (size_t i = 0; i < list.size(); i++)
	{
		if (i < list.size() / 2)
			array_one.push_back(*it);
		else
			array_two.push_back(*it);
		it++;
	}

	array_one = mergeSortContainers(array_one);
	array_two = mergeSortContainers(array_two);
	// std::cout << (*array_one.begin()) << std::endl;
	return (mergeTwoArrays( array_one, array_two ));
}


#endif
