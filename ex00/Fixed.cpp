/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:32:36 by corellan          #+#    #+#             */
/*   Updated: 2023/05/31 17:49:54 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _number(0)
{
	std::cout << "Default constructor called." << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &rhs)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = rhs;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called." << std::endl;
	return ;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return (this->_number);
}

void	Fixed::setRawBits(int const raw)
{
	this->_number = raw;
	return ;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assigment operator called." << std::endl;
	if (this == &rhs)
		return (*this);
	this->_number = rhs.getRawBits();
	return (*this);
}

int	Fixed::_FractBits = 8;
