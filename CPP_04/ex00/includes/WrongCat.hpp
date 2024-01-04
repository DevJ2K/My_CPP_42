/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:24:02 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 14:34:54 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat(/* args */);
	WrongCat( WrongCat const & src );
	~WrongCat();

	WrongCat	&operator=( WrongCat const & rhs );

	virtual std::string	getType( void ) const;
};

#endif