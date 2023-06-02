/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:32:36 by corellan          #+#    #+#             */
/*   Updated: 2023/06/02 14:48:56 by corellan         ###   ########.fr       */
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
	this->setRawBits(static_cast<int>(f * static_cast<float>(1 << Fixed::_FractBits) + (f >= 0 ? 0.5 : (- 0.5))));
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
	return ((static_cast<float>(this->getRawBits())) / static_cast<float>(1 << Fixed::_FractBits));
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_number = rhs.getRawBits();
	return (*this);
}

Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->_number + 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp;

	temp = *this;
	this->setRawBits(this->_number + 1);
	return (temp);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->_number - 1);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp;

	temp = *this;
	this->setRawBits(this->_number - 1);
	return (temp);
}

bool	Fixed::operator==(Fixed const &rhs)
{
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(Fixed const &rhs)
{
	if (this->getRawBits() != rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>(Fixed const &rhs)
{
	if (this->getRawBits() > rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(Fixed const &rhs)
{
	if (this->getRawBits() < rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(Fixed const &rhs)
{
	if (this->getRawBits() >= rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(Fixed const &rhs)
{
	if (this->getRawBits() <= rhs.getRawBits())
		return (true);
	else
		return (false);
}

Fixed	Fixed::operator+(Fixed const &rhs)
{
	int	result;

	result = this->getRawBits() + rhs.getRawBits();
	return ((static_cast<float>(result)) / static_cast<float>(1 << Fixed::_FractBits));
}

Fixed	Fixed::operator-(Fixed const &rhs)
{
	int	result;

	result = this->getRawBits() - rhs.getRawBits();
	return ((static_cast<float>(result)) / static_cast<float>(1 << Fixed::_FractBits));
}

Fixed	Fixed::operator*(Fixed const &rhs)
{
	int	result;

	result = this->getRawBits() * rhs.getRawBits();
	return ((static_cast<float>(result)) / static_cast<float>(1 << (2 * Fixed::_FractBits)));
}
Fixed	Fixed::operator/(Fixed const &rhs)
{
	int	result;

	result = ((this->getRawBits() * (1 << Fixed::_FractBits)) / (rhs.getRawBits()));
	return ((static_cast<float>(result)) / static_cast<float>(1 << Fixed::_FractBits));
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (static_cast<Fixed>(a) < static_cast<Fixed>(b))
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (static_cast<Fixed>(a) > static_cast<Fixed>(b))
		return (a);
	else
		return (b);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}

int	Fixed::_FractBits = 8;
