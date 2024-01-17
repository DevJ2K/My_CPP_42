/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:43:38 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 10:58:44 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & src );
		~ScavTrap();

		ScavTrap	&operator=( ScavTrap const & rhs );

		void	guardGate( void );
		void	attack(const std::string& target);
};

#endif