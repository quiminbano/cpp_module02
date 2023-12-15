/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:53:44 by corellan          #+#    #+#             */
/*   Updated: 2023/12/15 21:31:31 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	pointA(1.0f, 1.0f);
	Point	pointB(6.0f, 1.0f);
	Point	pointC(3.0f, 4.0f);
	Point	pointP(3.25f, 3.25f);
	Point	copy(pointP);
	Point	empty;
	bool	result;

	empty = copy;
	result = bsp(pointA, pointB, pointC, pointP);
	if (result == false)
		std::cout << "false" << std::endl;
	else
		std::cout << "true" << std::endl;
	result = bsp(pointA, pointB, pointC, copy);
	if (result == false)
		std::cout << "false" << std::endl;
	else
		std::cout << "true" << std::endl;
	result = bsp(pointA, pointB, pointC, empty);
	if (result == false)
		std::cout << "false" << std::endl;
	else
		std::cout << "true" << std::endl;
	return(0);
}
