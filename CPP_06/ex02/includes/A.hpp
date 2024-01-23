/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:52:04 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 17:17:59 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP

#include "Base.hpp"
#include <string>

class A : public Base
{
private:
public:
	A();
	~A();
	void displayType( void ) const;
};

#endif
