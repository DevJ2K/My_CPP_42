/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:25:17 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 10:59:01 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap( std::string name );
	FragTrap( FragTrap const & src );
	~FragTrap();

	FragTrap	&operator=( FragTrap const & rhs );
	void	highFivesGuys(void);
};




#endif