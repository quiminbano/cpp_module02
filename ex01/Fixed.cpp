/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:32:36 by corellan          #+#    #+#             */
/*   Updated: 2023/12/15 14:36:55 by corellan         ###   ########.fr       */
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
	if (this != &rhs)
		*this = rhs;
	return ;
}

Fixed::Fixed(int const i)
{
	this->setRawBits((i * (1 << Fixed::_FractBits)));
	std::cout << "Int constructor called." << std::endl;
	return ;
}

Fixed::Fixed(float const f)
{
	this->setRawBits(static_cast<int>(f * static_cast<float>(1 << Fixed::_FractBits) + (f >= 0 ? 0.5 : (- 0.5))));
	std::cout << "Float constructor called." << std::endl;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called." << std::endl;
	return ;
}

int		Fixed::getRawBits(void) const
{
	return (this->_number);
}

void	Fixed::setRawBits(int const raw)
{
	this->_number = raw;
	return ;
}

int		Fixed::toInt(void) const
{
	return (((this->getRawBits()) / (1 << Fixed::_FractBits)));
}

float	Fixed::toFloat(void) const
{
	return ((static_cast<float>(this->getRawBits())) / static_cast<float>(1 << Fixed::_FractBits));
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assigment operator called." << std::endl;
	if (this == &rhs)
		return (*this);
	this->_number = rhs.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}

int	Fixed::_FractBits = 8;
