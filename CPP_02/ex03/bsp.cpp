/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 00:06:24 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/02 11:41:59 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Colors.hpp"
#include <iostream>

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	float xa = a.getX().toFloat();
	float ya = a.getY().toFloat();

	float xb = b.getX().toFloat();
	float yb = b.getY().toFloat();

	float xc = c.getX().toFloat();
	float yc = c.getY().toFloat();

	float xm = point.getX().toFloat();
	float ym = point.getY().toFloat();

	bool angle_AMB = ((xa - xm) * (yb - ym)) - ((ya - ym) * (xb - xm)) < 0 ? false : true;
	bool angle_BMC = ((xb - xm) * (yc - ym)) - ((yb - ym) * (xc - xm)) < 0 ? false : true;
	bool angle_CMA = ((xc - xm) * (ya - ym)) - ((yc - ym) * (xa - xm)) < 0 ? false : true;

	bool same_angle = (angle_AMB == angle_BMC && angle_BMC == angle_CMA);
	if (same_angle == true)
		return (true);
	else
		return (false);
}
