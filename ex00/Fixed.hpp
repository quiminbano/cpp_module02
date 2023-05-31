/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:03:43 by corellan          #+#    #+#             */
/*   Updated: 2023/05/31 17:00:42 by corellan         ###   ########.fr       */
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
	~Fixed(void);

	Fixed	&operator=(Fixed const &rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:

	int			_number;

	static int	_FractBits;
};

#endif