/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:26:51 by corellan          #+#    #+#             */
/*   Updated: 2023/12/15 20:22:28 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	getArea(Fixed sideA, Fixed sideB, Fixed sideC)
{
	Fixed	semiPerimeter;
	Fixed	squaredArea;
	Fixed	area;
	Fixed	temp;

	semiPerimeter = ((sideA + sideB + sideC) / (Fixed(2.0f)));
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
	if (a < Fixed(0.0f))
		a = (a * Fixed(-1.0f));
	if (b < Fixed(0))
		b = (b * Fixed(-1.0f));
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
	std::cout << "side between A and B: " << sideAB << std::endl; 
	sideAC = getSide(a, c);
	std::cout << "side between A and C: " << sideAC << std::endl; 
	sideBC = getSide(b, c);
	std::cout << "side between B and C: " << sideBC << std::endl; 
	sideAPoint = getSide(a, point);
	std::cout << "side between A and Point: " << sideAPoint << std::endl; 
	sideBPoint = getSide(b, point);
	std::cout << "side between B and Point: " << sideBPoint << std::endl; 
	sideCPoint = getSide(c, point);
	std::cout << "side between C and Point: " << sideCPoint << std::endl; 
	areaTriangle = getArea(sideAB, sideAC, sideBC);
	areaABPoint = getArea(sideAPoint, sideBPoint, sideAB);
	areaACPoint = getArea(sideAPoint, sideCPoint, sideAC);
	areaBCPoint = getArea(sideBPoint, sideCPoint, sideBC);
	std::cout << "Area triangle: " << areaTriangle << std::endl;
	std::cout << "Area combined: " << (areaABPoint + areaACPoint + areaBCPoint) << std::endl;
	std::cout << "Area ABP: " << areaABPoint << std::endl;
	std::cout << "Area ACP: " << areaACPoint << std::endl;
	std::cout << "Area BCP: " << areaBCPoint << std::endl;
	if (areaABPoint == Fixed(0.0f) || areaACPoint == Fixed(0.0f) || areaBCPoint == Fixed(0.0f))
		return (false);
	if ((std::roundf(areaTriangle.toFloat() * 10.0f) / 10.0f) == (std::roundf((areaABPoint + areaACPoint + areaBCPoint).toFloat() * 10.0f) / 10.0f))
		return (true);
	return (false);
}