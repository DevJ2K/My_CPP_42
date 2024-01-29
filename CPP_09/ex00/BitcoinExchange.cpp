/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:57:24 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/29 09:21:37 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Colors.hpp"
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

static bool	open_success( std::ifstream & file, std::string filename )
{
	bool success = true;
	if (file.fail() || file.bad())
	{
		display_err("Failed to open the file -> " + filename);
		success = false;
	}
	else if (file.eof())
	{
		display_err("The input file is empty -> " + filename);
		success = false;
	}
	if (success == false)
	{
		if (file.is_open())
			file.close();
	}
	return (success);
}


static bool	is_only_numbers( std::string str )
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
}

static bool	check_date_format( std::string date )
{
	std::istringstream	iss_year(date.substr(0, 4));
	std::istringstream	iss_month(date.substr(5, 2));
	std::istringstream	iss_day(date.substr(8, 2));

	unsigned int	year;
	unsigned int	month;
	unsigned int	day;

	iss_year >> year;
	iss_month >> month;
	iss_day >> day;

	if (date.length() > 10 && date.substr(10) != " ")
		return (display_err("Invalid date format => " + date), false);

	if ((!is_only_numbers(date.substr(0, 4))
	|| !iss_year.eof() || iss_year.fail()
	|| (year < 0 || year > 9999)))
		return (display_err("Invalid year format => " + date.substr(0, 4)), false);

	if ((!is_only_numbers(date.substr(5, 2))
	|| !iss_month.eof() || iss_month.fail()
	|| (month < 1 || month > 12)))
		return (display_err("Invalid month format => " + date.substr(5, 2)), false);

	if ((!is_only_numbers(date.substr(8, 2))
	|| !iss_day.eof() || iss_day.fail()
	|| (day < 1 || day > 31)))
		return (display_err("Invalid day format => " + date.substr(8, 2)), false);

	return (true);
}

static bool	check_value_range( std::string value )
{
	std::istringstream	iss(value);
	float	nb;

	iss >> nb;
	if (!iss.eof() || iss.fail())
		return (display_err("Invalid number format => " + value), false);
	if (nb < 0)
		return (display_err("Not a positive number. Numbers need to be between 0 and 1000."), false);
	if (nb > 1000)
		return (display_err("Too large a number. Numbers need to be between 0 and 1000."), false);
	return (true);
}

static bool	check_data_value( std::string value )
{
	std::istringstream	iss(value);
	double	nb;

	iss >> nb;
	if (!iss.eof() || iss.fail())
		return (display_err("Invalid number format => " + value), false);
	return (true);
}

static std::map<std::string, double>	get_data( const char * data_filename )
{
	std::ifstream					data_file;
	std::map<std::string, double>	data;

	data_file.open(data_filename);
	if (open_success(data_file, data_filename) == 0)
	{
		if (data_file.is_open() == true)
		{
			data_file.close();
			throw BitcoinExchange::BadFileException();
		}
	}
	std::string	line;
	while (std::getline(data_file, line))
	{
		if (line.compare("date,exchange_rate") == 0)
			continue ;
		else if (line.length() < 12)
		{
			display_err("bad input => " + line);
			continue ;
		}
		else if (check_date_format(line.substr(0, 10)) == false)
			continue ;

		else if (check_data_value(line.substr(11)) == false)
			continue ;
		double	fvalue;
		std::istringstream iss(line.substr(11));
		iss >> fvalue;
		if (!iss.eof() || iss.fail())
			throw BitcoinExchange::BadDataValueException();

		data[line.substr(0, 10)] = fvalue;
	}
	return (data);
}

BitcoinExchange::BitcoinExchange( const char * data_file, const char * input_filename )
{
	this->_data = get_data(data_file);
	std::ifstream	input_file;

	input_file.open(input_filename);
	if (open_success(input_file, input_filename) == 0)
	{
		input_file.close();
		throw BitcoinExchange::BadFileException();
	}

	std::string	line;
	while (std::getline(input_file, line))
	{
		if (line.empty())
			continue ;
		if (line.compare("date | value") == 0)
			continue ;
		if (line.substr(0, 1) == "#")
		{
			std::cout << BHBLACK << line << RESET << std::endl;
			continue ;
		}
		else if (line.length() < 14)
		{
			display_err("bad input => " + line);
			continue ;
		}

		else if (check_date_format(line.substr(0, 11)) == false)
			continue ;

		else if (check_value_range(line.substr(13)) == false)
			continue ;

		std::istringstream	iss(line.substr(13));
		float nb;
		iss >> nb;
		std::map<std::string, double>::iterator	ite = this->_data.end();

		ite--;
		bool date_found = false;
		while (date_found == false && ite != this->_data.begin())
		{
			if (std::max((*ite).first, line.substr(0, 10)) == line.substr(0, 10))
			{
				std::cout << line.substr(0, 10) << " => "
				<< std::setprecision(4) << nb << " = "
				<< std::setprecision(5) << (nb * (*ite).second) << std::endl;
				date_found = true;
			}
			ite--;
		}
		if (date_found)
			continue ;
		if (std::max((*ite).first, line.substr(0, 10)) == line.substr(0, 10))
			std::cout << std::setprecision(3) << line.substr(0, 10) << " => " << nb << " = " << (nb * (*ite).second) << std::endl;
		else
			display_err("No value found because the date is too old => " + line.substr(0, 10));
	}
}

const char	*BitcoinExchange::BadFileException::what() const throw()
{
	return ("Bad file");
}

const char	*BitcoinExchange::BadDataValueException::what() const throw()
{
	return ("Bad data value");
}

BitcoinExchange::~BitcoinExchange()
{
}
