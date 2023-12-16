/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:05:18 by corellan          #+#    #+#             */
/*   Updated: 2023/12/16 12:28:01 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <cmath>

class	Point
{
public:

	Point(void);
	Point(float const xComing, float const yComing);
	Point(Point const &rhs);
	~Point(void);

	Point	&operator=(Point const &rhs);

	const Fixed	&getX(void) const;
	const Fixed	&getY(void) const;

private:

	Fixed const	x;
	Fixed const y;

};

#endif