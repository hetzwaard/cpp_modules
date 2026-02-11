/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/11 18:54:00 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/11 19:03:43 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					_raw;
	static const int	_fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &value);
	Fixed(const int integerVar);
	Fixed(const float floatVar);
	Fixed	&operator=(const Fixed &value);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed);

#endif