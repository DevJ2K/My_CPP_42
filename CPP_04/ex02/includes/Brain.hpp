/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:33:42 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 20:56:45 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <string>

class Brain
{
	private:
		static const int	_nb_ideas = 10;
		std::string	_ideas[_nb_ideas];
	public:
		Brain();
		Brain( Brain const & src );
		~Brain();

		Brain	&operator=( Brain const & rhs );

		std::string	getIdeas( int index ) const;
		int	getNbIdeas( void ) const;
		void		setIdeas( int index, std::string ideas );

};

#endif