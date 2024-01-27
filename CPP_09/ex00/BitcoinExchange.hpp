/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:57:21 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/27 14:06:47 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <string>
#include <map>
#include <exception>

# define DATA_FILE "data.csv"

class BitcoinExchange
{
private:
	std::map<std::string, double>	_data;
	BitcoinExchange();
public:
	BitcoinExchange( const char * data_file, const char * input_filename );
	~BitcoinExchange();

	BitcoinExchange	&operator=( BitcoinExchange const & rhs );

	class BadFileException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class BadDataValueException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
};

void	display_err( std::string err_msg );

#endif
