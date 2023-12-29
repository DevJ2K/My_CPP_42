/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:08:13 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/29 15:25:07 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
#include <string>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie( std::string name );
		~Zombie();

		void	announce( void );
};

#endif
