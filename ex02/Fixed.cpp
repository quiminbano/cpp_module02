/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:32:36 by corellan          #+#    #+#             */
/*   Updated: 2023/06/01 15:47:09 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _number(0)
{
	return ;
}

Fixed::Fixed(Fixed const &rhs)
{
	*this = rhs;
	return ;
}

Fixed::Fixed(int const i)
{
	this->setRawBits((i * (1 << Fixed::_FractBits)));
	return ;
}

Fixed::Fixed(float const f)
{
	this->setRawBits((int)(f * (float)(1 << Fixed::_FractBits) + (f >= 0 ? 0.5 : (- 0.5))));
	return ;
}

Fixed::~Fixed(void)
{
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
	return (((float)this->getRawBits()) / (float)(1 << Fixed::_FractBits));
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_number = rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &rhs)
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const &rhs)
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const &rhs)
{
	return (this->toFloat() * rhs.toFloat());
}
Fixed	Fixed::operator/(Fixed const &rhs)
{
	return (this->toFloat() / rhs.toFloat());
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}

int	Fixed::_FractBits = 8;
