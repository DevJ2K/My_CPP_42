/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:37:37 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 16:32:38 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <stdint.h>
#include <string>

class Data
{
private:
	int			_day;
	std::string	_month;
	int			_year;
	Data();

public:
	Data( int day, std::string month, int year );
	Data( Data const &src );
	~Data();

	void		displayData( void ) const;
	int			getDay( void ) const;
	std::string	getMonth( void ) const;
	int			getYear( void ) const;

	Data	&operator=( Data const &rhs );

	static Data	*deserialize(uintptr_t raw);
};


#endif
