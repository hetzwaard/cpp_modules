/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/02 11:54:22 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/02 12:08:15 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
const T	&min(const T &a, const T &b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
const T	&max(const T &a, const T &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif