/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:50:06 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 17:05:41 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base
{
protected:
	Base();
public:
	virtual ~Base();

	Base* generate(void) const;
	void identify(Base *p) const;
	void identify(Base &p) const;

	virtual void displayType( void ) const = 0;

};


#endif
