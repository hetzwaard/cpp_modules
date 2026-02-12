/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/12 13:26:59 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/12 13:43:45 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
}

Point::Point(Point const &other) : _x(other._x), _y(other._y)
{
}

Point	&Point::operator=(Point const &other)
{
	(void)other;
	return (*this);
}

Point::~Point()
{
}

Fixed const	&Point::getX() const
{
	return (_x);
}

Fixed const	&Point::getY() const
{
	return (_y);
}
