/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:22:59 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/30 12:13:27 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	Weapon & _weapon;
public:
	HumanA( std::string name, Weapon & weapon );
	~HumanA();

	void	attack( void );
};

#endif
