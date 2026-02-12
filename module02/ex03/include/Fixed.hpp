/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/11 19:20:41 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/11 19:53:05 by mahkilic      ########   odam.nl         */
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

	bool	operator>(const Fixed	&value) const;
	bool	operator<(const Fixed	&value) const;
	bool	operator>=(const Fixed	&value) const;
	bool	operator<=(const Fixed	&value) const;
	bool	operator==(const Fixed	&value) const;
	bool	operator!=(const Fixed	&value) const;

	Fixed	operator+(const Fixed	&value) const;
	Fixed	operator-(const Fixed	&value) const;
	Fixed	operator*(const Fixed	&value) const;
	Fixed	operator/(const Fixed	&value) const;

	Fixed	&operator++(void);
	Fixed	operator++(int intVal);
	Fixed	&operator--(void);
	Fixed	operator--(int intVal);

	static Fixed		&min(Fixed &value1, Fixed &value2);
	static const Fixed	&min(const Fixed &value1, const Fixed &value2);
	static Fixed		&max(Fixed &value1, Fixed &value2);
	static const Fixed	&max(const Fixed &value1, const Fixed &value2);
};

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed);

#endif
