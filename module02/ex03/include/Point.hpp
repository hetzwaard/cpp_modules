/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/12 13:26:11 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/12 13:31:25 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point
{
private:
	Fixed const	_x;
	Fixed const	_y;

public:
	Point();
	Point(float const x, float const y);
	Point(Point const &other);
	Point	&operator=(Point const &other);
	~Point();

	Fixed const	&getX() const;
	Fixed const	&getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
