/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bsp.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/12 13:27:13 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/12 15:26:52 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed const	t1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
	Fixed const	t2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
	Fixed const	t3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());

	if (t1 == 0 || t2 == 0 || t3 == 0)
		return (false);

	bool	negative = (t1 < 0) || (t2 < 0) || (t3 < 0);
	bool	positive = (t1 > 0) || (t2 > 0) || (t3 > 0);

	return (!(negative && positive));
}
