/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:03:43 by corellan          #+#    #+#             */
/*   Updated: 2023/12/15 14:58:27 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:

	Fixed(void);
	Fixed(Fixed const &rhs);
	Fixed(int const i);
	Fixed(float const f);
	~Fixed(void);

	Fixed	&operator=(Fixed const &rhs);
	Fixed	operator+(Fixed const &rhs);
	Fixed	operator-(Fixed const &rhs);
	Fixed	operator*(Fixed const &rhs);
	Fixed	operator/(Fixed const &rhs);
	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);
	bool	operator==(Fixed const &rhs);
	bool	operator!=(Fixed const &rhs);
	bool	operator>(Fixed const &rhs);
	bool	operator<(Fixed const &rhs);
	bool	operator>=(Fixed const &rhs);
	bool	operator<=(Fixed const &rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;

	static Fixed		&min(Fixed &a, Fixed &b);
	static Fixed const	&min(Fixed const &a, Fixed const &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static Fixed const	&max(Fixed const &a, Fixed const &b);

private:

	int			_number;

	static int	_FractBits;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif