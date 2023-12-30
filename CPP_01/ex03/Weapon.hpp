/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:20:30 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/30 12:14:01 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon( std::string type );
		~Weapon();

	std::string const & getType( void );
	void	setType( std::string type );
};

#endif
