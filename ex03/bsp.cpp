/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:26:51 by corellan          #+#    #+#             */
/*   Updated: 2023/12/15 16:47:08 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	getArea(Fixed sideA, Fixed sideB, Fixed sideC)
{
	Fixed	semiPerimeter;
	Fixed	squaredArea;
	Fixed	area;

	semiPerimeter = ((sideA + sideB + sideC) / (Fixed(2)));
	squaredArea = (semiPerimeter * (semiPerimeter - sideA) * (semiPerimeter - sideB) * (semiPerimeter - sideC));
	area = Fixed(sqrtf(squaredArea.toFloat()));
	return (area);
}

static Fixed	getSide(Point first, Point second)
{
	Fixed	a;
	Fixed	b;
	Fixed	cSquared;
	Fixed	result;

	a = (static_cast<Fixed>(second.getX()) - static_cast<Fixed>(first.getX()));
	b = (static_cast<Fixed>(second.getY()) - static_cast<Fixed>(first.getY()));
	if (a < Fixed(0))
		a = (a * Fixed(-1));
	if (b < Fixed(0))
		b = (b * Fixed(-1));
	cSquared = (a * a) + (b * b);
	result = Fixed(sqrtf(cSquared.toFloat()));
	return (result);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	sideAB;
	Fixed	sideAC;
	Fixed	sideBC;
	Fixed	sideAPoint;
	Fixed	sideBPoint;
	Fixed	sideCPoint;
	Fixed	areaTriangle;
	Fixed	areaABPoint;
	Fixed	areaACPoint;
	Fixed	areaBCPoint;

	sideAB = getSide(a, b);
	sideAC = getSide(a, c);
	sideBC = getSide(b, c);
	sideAPoint = getSide(a, point);
	sideBPoint = getSide(b, point);
	sideCPoint = getSide(c, point);
	areaTriangle = getArea(sideAB, sideAC, sideBC);
	areaABPoint = getArea(sideAPoint, sideBPoint, sideAB);
	areaACPoint = getArea(sideAPoint, sideCPoint, sideAC);
	areaBCPoint = getArea(sideBPoint, sideCPoint, sideBC);
	if (areaABPoint == Fixed(0) || areaACPoint == Fixed(0) || areaBCPoint == Fixed(0))
		return (false);
	if (areaTriangle == (areaABPoint + areaACPoint + areaBCPoint))
		return (true);
	return (false);
}