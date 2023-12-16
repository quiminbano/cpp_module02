/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:26:51 by corellan          #+#    #+#             */
/*   Updated: 2023/12/16 13:57:28 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	ft_sqrt(Fixed const &squared)
{
	Fixed	current;
	Fixed	next;
	int		counter;

	counter = 0;
	current = (static_cast<Fixed>(squared) / Fixed(2.0f));
	if (current == Fixed(0.0f))
	{
		next = Fixed(0.0f);
		return next;
	}
	while (1)
	{
		next = ((current + ((static_cast<Fixed>(squared)) / current)) / Fixed(2.0f));
		if (next == current)
			break ;
		counter++;
		if (counter == 20)
			break ;
		current = next;
	}
	return (next);
}

static Fixed	getArea(Fixed sideA, Fixed sideB, Fixed sideC)
{
	Fixed	semiPerimeter;
	Fixed	squaredArea;
	Fixed	area;
	Fixed	temp;

	semiPerimeter = ((sideA + sideB + sideC) / (Fixed(2.0f)));
	squaredArea = (semiPerimeter * (semiPerimeter - sideA) * (semiPerimeter - sideB) * (semiPerimeter - sideC));
	area = ft_sqrt(squaredArea);
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
	result = ft_sqrt(cSquared);
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
	Fixed	difference;

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
	std::cout << "Area triangle: " << areaTriangle << std::endl;
	std::cout << "Area combined: " << (areaABPoint + areaACPoint + areaBCPoint) << std::endl;
	std::cout << "Area ABP: " << areaABPoint << std::endl;
	std::cout << "Area ACP: " << areaACPoint << std::endl;
	std::cout << "Area BCP: " << areaBCPoint << std::endl;
	if (areaABPoint == Fixed(0.0f) || areaACPoint == Fixed(0.0f) || areaBCPoint == Fixed(0.0f))
		return (false);
	if ((areaTriangle - (areaABPoint + areaACPoint + areaBCPoint)) >= Fixed(0.0f))
		difference = (areaTriangle - (areaABPoint + areaACPoint + areaBCPoint));
	else
		difference = ((areaABPoint + areaACPoint + areaBCPoint) - areaTriangle);
	if (difference < Fixed(0.1f))
		return (true);
	return (false);
}