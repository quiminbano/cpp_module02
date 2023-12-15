/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:53:44 by corellan          #+#    #+#             */
/*   Updated: 2023/12/15 15:02:03 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << std::endl << std::endl << "++++++++++++++++++++++++++++++++++++++++++  EXTRA TESTING  ++++++++++++++++++++++++++++++++++++++++++" << std::endl << std::endl;
	std::cout << "The value of a is " << a << ". The value of b is " << b << ". The value of a + b the first time is " << (a + b) << std::endl;
	std::cout << "The value of a is " << a << ". The value of b is " << b << ". The value of a + b the second time is " << (a + b) << std::endl;
	std::cout << "The value of a is " << a << ". The value of b is " << b << ". The value of a - b the first time is " << (a - b) << std::endl;
	std::cout << "The value of a is " << a << ". The value of b is " << b << ". The value of a - b the second time is " << (a - b) << std::endl;
	std::cout << "The value of a is " << a << ". The value of b is " << b << ". The value of a * b the first time is " << (a * b) << std::endl;
	std::cout << "The value of a is " << a << ". The value of b is " << b << ". The value of a * b the second time is " << (a * b) << std::endl;
	std::cout << "The value of a is " << a << ". The value of b is " << b << ". The value of a / b the first time is " << (a / b) << std::endl;
	std::cout << "The value of a is " << a << ". The value of b is " << b << ". The value of a / b the second time is " << (a / b) << std::endl;
	std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++  END OF TESTING  ++++++++++++++++++++++++++++++++++++++++++" << std::endl << std::endl;
	return (0);
}
