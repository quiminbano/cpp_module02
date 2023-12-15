/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:12:31 by corellan          #+#    #+#             */
/*   Updated: 2023/12/15 15:53:49 by corellan         ###   ########.fr       */
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

Point	&Point::operator=(Point const &rhs)
{
	Point	temp(rhs.x.toFloat(), rhs.y.toFloat());

	return (temp);
}

const Fixed	&Point::getX(void) const
{
	return (x);
}

const Fixed	&Point::getY(void) const
{
	return (y);
}
