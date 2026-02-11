/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/11 18:53:45 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/11 19:15:17 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = value;
}

Fixed::Fixed(const int integerVar)
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw = integerVar << _fractionalBits;
}

Fixed::Fixed(const float floatVar)
{
	std::cout << "Float constructor called" << std::endl;
	this->_raw = roundf(floatVar * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &value)
		_raw = value._raw;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed)
{
	return (out << fixed.toFloat());
}

float	Fixed::toFloat(void) const
{
	return ((float)_raw / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return ((int)_raw >> _fractionalBits);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_raw);
}

void	Fixed::setRawBits(int const raw)
{
	_raw = raw;
}
