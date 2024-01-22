/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:33:33 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/22 18:05:57 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class ScalarConverter
{
private:

	enum e_type
	{
		CHAR = 1,
		INT = 2,
		FLOAT = 3,
		DOUBLE = 4,
		INVALID = 5
	};

	ScalarConverter();

public:
	~ScalarConverter();

	static void	convert( std::string value );

};
