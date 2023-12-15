/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:12:31 by corellan          #+#    #+#             */
/*   Updated: 2023/12/15 21:50:32 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
	return ;
}

Point::Point(float const xComing, float const yComing) : x(xComing), y(yComing)
{
	return ;
}

Point::Point(Point const &rhs) : x(rhs.x), y(rhs.y)
{
	return ;
}

Point::~Point(void)
{
	return ;
}

void	Point::swapNumbers(Fixed *a, Fixed *b)
{
	Fixed	*temp;

	*temp = *a;
	*a = *b;
	*b = *temp;

	return ;
}

/* This operator definition has some assigments that could be consider
bad practice. The reason to use the swapNumbers function in the operator is because
in the subject is mandatory to define the copy assigment operator in the public side.*/

Point	&Point::operator=(Point const &rhs)
{
	Point		temp(rhs.x.toFloat(), rhs.y.toFloat());
	Fixed		*variableThis;
	Fixed		*variableTemp;

	if (this != &rhs)
	{
		variableThis = const_cast<Fixed *>(&(this->x));
		variableTemp = const_cast<Fixed *>(&(temp.x));
		swapNumbers(variableThis, variableTemp);
		variableThis = const_cast<Fixed *>(&(this->y));
		variableTemp = const_cast<Fixed *>(&(temp.y));
		swapNumbers(variableThis, variableTemp);
	}
	return (*this);
}

const Fixed	&Point::getX(void) const
{
	return (x);
}

const Fixed	&Point::getY(void) const
{
	return (y);
}
