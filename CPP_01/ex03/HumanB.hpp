/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:23:46 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/30 13:58:08 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
#include "Weapon.hpp"

class HumanB
{
private:
	std::string _name;
	Weapon *_weapon;
public:
	HumanB( std::string name );
	~HumanB();

	void	attack( void );
	void	setWeapon( Weapon &weapon );
	void	removeWeapon( void );
};

#endif
