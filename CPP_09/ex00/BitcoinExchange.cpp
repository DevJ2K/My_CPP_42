/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:57:24 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/26 16:57:31 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Colors.hpp"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>

static bool	open_success( std::ifstream & file, std::string filename )
{
	bool success = true;
	if (file.fail())
	{
		display_err("Failed to open the file -> " + filename);
		success = false;
	}
	else if (file.bad())
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

		double	fvalue;
		// std::cout << line.substr(11, line.length() - 10) << " | ";
		std::istringstream iss(line.substr(11, line.length() - 10));
		iss >> fvalue;
		// std::cout << std::setprecision(9) << fvalue << std::endl;
		if (!iss.eof() || iss.fail())
			throw BitcoinExchange::BadDataValueException();

		data[line.substr(0, 10)] = fvalue;
	}
	return (data);
}

static bool	check_date_format( std::string date )
{
	std::istringstream	iss_year(date.substr(0, 4));
	std::istringstream	iss_month(date.substr(5, 2));
	std::istringstream	iss_day(date.substr(8, 2));

	int	year;
	int	month;
	int	day;

	iss_year >> year;
	iss_month >> month;
	iss_day >> day;

	// std::cout << year << " || ";
	// std::cout << month << " || ";
	// std::cout << day << std::endl;

	if ((!iss_year.eof() || iss_year.fail() || (year < 0 || year > 9999)))
		return (display_err("Invalid year format => " + date.substr(0, 4)), false);
	if ((!iss_month.eof() || iss_month.fail() || (month < 1 || month > 12)))
		return (display_err("Invalid month format => " + date.substr(5, 2)), false);
	if ((!iss_day.eof() || iss_day.fail() || (day < 1 || day > 31)))
		return (display_err("Invalid day format => " + date.substr(8, 2)), false);


	// std::cout << date.substr(0, 4) << " | ";
	// std::cout << date.substr(5, 2) << " | ";
	// std::cout << date.substr(8, 2) << std::endl;
	return (true);
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

		else if (check_date_format(line.substr(0, 10)) == false)
			continue ;

		std::cout << BHGREEN << "Valid input !" << RESET << std::endl;
		// double	fvalue;
		// std::cout << line.substr(11, line.length() - 10) << " | ";
		// std::istringstream iss(line.substr(11, line.length() - 10));
		// iss >> fvalue;
		// std::cout << std::setprecision(9) << fvalue << std::endl;
		// if (!iss.eof() || iss.fail())
		// 	throw BitcoinExchange::BadDataValueException();

		// data[line.substr(0, 10)] = fvalue;
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
