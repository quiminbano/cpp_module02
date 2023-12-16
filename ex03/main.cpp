/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:53:44 by corellan          #+#    #+#             */
/*   Updated: 2023/12/16 14:46:30 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	//Triangle1
	Point	pointA(1.0f, 1.0f);
	Point	pointB(6.0f, 1.0f);
	Point	pointC(3.0f, 4.0f);
	Point	pointP1(3.0f, 3.0f);
	Point	pointP2(1.0f, 3.0f);
	Point	pointP3(3.0f, 1.0f);
	Point	pointP4(6.0f, 1.0f);

	//Triangle 2
	Point	pointA2(-4.0f, -3.0f);
	Point	pointB2(-9.0f, -3.0f);
	Point	pointC2(-6.0f, -6.0f);
	Point	pointP12(-6.0f, -5.0f);
	Point	pointP22(-4.0f, -5.0f);
	Point	pointP32(-6.0f, -3.0f);
	Point	pointP42(-9.0f, -3.0f);

	//Result bsp
	bool	result;

	std::cout << std::endl;

	std::cout << std::endl << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Triangle 1 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl << std::endl;

	std::cout << "P1" << std::endl;
	std::cout << "PointA of the triangle: " << pointA.getX() << "," << pointA.getY() << " ";
	std::cout << "PointB of the triangle: " << pointB.getX() << "," << pointB.getY() << " ";
	std::cout << "PointC of the triangle: " << pointC.getX() << "," << pointC.getY() << " ";
	std::cout << "P1: " << pointP1.getX() << "," << pointP1.getY() << std::endl;
	result = bsp(pointA, pointB, pointC, pointP1);
	if (result == false)
		std::cout << "\033[31m" << "The point P1 " << pointP1.getX() << "," << pointP1.getY() << " is not inside the triangle" << "\033[0m" << std::endl;
	else
		std::cout << "\033[32m" << "The point P1 " << pointP1.getX() << "," << pointP1.getY() << " is inside the triangle" << "\033[0m" << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "P2" << std::endl;
	std::cout << "PointA of the triangle: " << pointA.getX() << "," << pointA.getY() << " ";
	std::cout << "PointB of the triangle: " << pointB.getX() << "," << pointB.getY() << " ";
	std::cout << "PointC of the triangle: " << pointC.getX() << "," << pointC.getY() << " ";
	std::cout << "P2: " << pointP2.getX() << "," << pointP2.getY() << std::endl;
	result = bsp(pointA, pointB, pointC, pointP2);
	if (result == false)
		std::cout << "\033[31m" << "The point P2 " << pointP2.getX() << "," << pointP2.getY() << " is not inside the triangle" << "\033[0m" << std::endl;
	else
		std::cout << "\033[32m" << "The point P2 " << pointP2.getX() << "," << pointP2.getY() << " is inside the triangle" << "\033[0m" << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "P3" << std::endl;
	std::cout << "PointA of the triangle: " << pointA.getX() << "," << pointA.getY() << " ";
	std::cout << "PointB of the triangle: " << pointB.getX() << "," << pointB.getY() << " ";
	std::cout << "PointC of the triangle: " << pointC.getX() << "," << pointC.getY() << " ";
	std::cout << "P3: " << pointP3.getX() << "," << pointP3.getY() << std::endl;
	result = bsp(pointA, pointB, pointC, pointP3);
	if (result == false)
		std::cout << "\033[31m" << "The point P3 " << pointP3.getX() << "," << pointP3.getY() << " is not inside the triangle" << "\033[0m" << std::endl;
	else
		std::cout << "\033[32m" << "The point P3 " << pointP3.getX() << "," << pointP3.getY() << " is inside the triangle" << "\033[0m" << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "P4" << std::endl;
	std::cout << "PointA of the triangle: " << pointA.getX() << "," << pointA.getY() << " ";
	std::cout << "PointB of the triangle: " << pointB.getX() << "," << pointB.getY() << " ";
	std::cout << "PointC of the triangle: " << pointC.getX() << "," << pointC.getY() << " ";
	std::cout << "P4: " << pointP4.getX() << "," << pointP4.getY() << std::endl;
	result = bsp(pointA, pointB, pointC, pointP4);
	if (result == false)
		std::cout << "\033[31m" << "The point P4 " << pointP4.getX() << "," << pointP4.getY() << " is not inside the triangle" << "\033[0m" << std::endl;
	else
		std::cout << "\033[32m" << "The point P4 " << pointP4.getX() << "," << pointP4.getY() << " is inside the triangle" << "\033[0m" << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << std::endl << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Triangle 2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl << std::endl;

	std::cout << "P1'" << std::endl;
	std::cout << "PointA' of the triangle: " << pointA2.getX() << "," << pointA2.getY() << " ";
	std::cout << "PointB' of the triangle: " << pointB2.getX() << "," << pointB2.getY() << " ";
	std::cout << "PointC' of the triangle: " << pointC2.getX() << "," << pointC2.getY() << " ";
	std::cout << "P1': " << pointP12.getX() << "," << pointP12.getY() << std::endl;
	result = bsp(pointA2, pointB2, pointC2, pointP12);
	if (result == false)
		std::cout << "\033[31m" << "The point P1' " << pointP12.getX() << "," << pointP12.getY() << " is not inside the triangle" << "\033[0m" << std::endl;
	else
		std::cout << "\033[32m" << "The point P1' " << pointP12.getX() << "," << pointP12.getY() << " is inside the triangle" << "\033[0m" << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "P2'" << std::endl;
	std::cout << "PointA' of the triangle: " << pointA2.getX() << "," << pointA2.getY() << " ";
	std::cout << "PointB' of the triangle: " << pointB2.getX() << "," << pointB2.getY() << " ";
	std::cout << "PointC' of the triangle: " << pointC2.getX() << "," << pointC2.getY() << " ";
	std::cout << "P2': " << pointP22.getX() << "," << pointP22.getY() << std::endl;
	result = bsp(pointA2, pointB2, pointC2, pointP22);
	if (result == false)
		std::cout << "\033[31m" << "The point P2' " << pointP22.getX() << "," << pointP22.getY() << " is not inside the triangle" << "\033[0m" << std::endl;
	else
		std::cout << "\033[32m" << "The point P2' " << pointP22.getX() << "," << pointP22.getY() << " is inside the triangle" << "\033[0m" << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "P3'" << std::endl;
	std::cout << "PointA' of the triangle: " << pointA2.getX() << "," << pointA2.getY() << " ";
	std::cout << "PointB' of the triangle: " << pointB2.getX() << "," << pointB2.getY() << " ";
	std::cout << "PointC' of the triangle: " << pointC2.getX() << "," << pointC2.getY() << " ";
	std::cout << "P3': " << pointP32.getX() << "," << pointP32.getY() << std::endl;
	result = bsp(pointA2, pointB2, pointC2, pointP32);
	if (result == false)
		std::cout << "\033[31m" << "The point P1' " << pointP32.getX() << "," << pointP32.getY() << " is not inside the triangle" << "\033[0m" << std::endl;
	else
		std::cout << "\033[32m" << "The point P1' " << pointP32.getX() << "," << pointP32.getY() << " is inside the triangle" << "\033[0m" << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "P4'" << std::endl;
	std::cout << "PointA' of the triangle: " << pointA2.getX() << "," << pointA2.getY() << " ";
	std::cout << "PointB' of the triangle: " << pointB2.getX() << "," << pointB2.getY() << " ";
	std::cout << "PointC' of the triangle: " << pointC2.getX() << "," << pointC2.getY() << " ";
	std::cout << "P4': " << pointP42.getX() << "," << pointP42.getY() << std::endl;
	result = bsp(pointA2, pointB2, pointC2, pointP42);
	if (result == false)
		std::cout << "\033[31m" << "The point P4' " << pointP42.getX() << "," << pointP42.getY() << " is not inside the triangle" << "\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "The point P4' " << pointP42.getX() << "," << pointP42.getY() << " is inside the triangle" << "\033[0m" << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << std::endl << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ TESTING COPY CONSTRUCTOR OF POINT ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl << std::endl;
	Point	copy(pointP1);
	std::cout << "PointA of the triangle: " << pointA.getX() << "," << pointA.getY() << " ";
	std::cout << "PointB of the triangle: " << pointB.getX() << "," << pointB.getY() << " ";
	std::cout << "PointC of the triangle: " << pointC.getX() << "," << pointC.getY() << " ";
	std::cout << "PointCopy: " << copy.getX() << "," << copy.getY() << std::endl;
	result = bsp(pointA, pointB, pointC, copy);
	if (result == false)
		std::cout << "\033[31m" << "The point Copy " << copy.getX() << "," << copy.getY() << " is not inside the triangle" << "\033[0m" << std::endl;
	else
		std::cout << "\033[32m" << "The point Copy " << copy.getX() << "," << copy.getY() << " is inside the triangle" << "\033[0m" << std::endl;
	std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ END OF TESTING ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl << std::endl;

	std::cout << std::endl << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ TESTING COPY ASSIGMENT OF POINT ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl << std::endl;
	Point	empty;
	empty = pointP1;
	std::cout << "PointA of the triangle: " << pointA.getX() << "," << pointA.getY() << " ";
	std::cout << "PointB of the triangle: " << pointB.getX() << "," << pointB.getY() << " ";
	std::cout << "PointC of the triangle: " << pointC.getX() << "," << pointC.getY() << " ";
	std::cout << "PointP: " << empty.getX() << "," << empty.getY() << std::endl;
	result = bsp(pointA, pointB, pointC, empty);
	if (result == false)
		std::cout << "\033[31m" << "The point empty " << empty.getX() << "," << empty.getY() << " is not inside the triangle" << "\033[0m" << std::endl;
	else
		std::cout << "\033[32m" << "The point empty " << empty.getX() << "," << empty.getY() << " is inside the triangle" << "\033[0m" << std::endl;
	std::cout << std::endl << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ END OF TESTING +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl << std::endl;
	return(0);
}
