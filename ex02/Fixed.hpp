/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:03:43 by corellan          #+#    #+#             */
/*   Updated: 2023/06/01 20:19:42 by corellan         ###   ########.fr       */
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

private:

	int			_number;

	static int	_FractBits;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif