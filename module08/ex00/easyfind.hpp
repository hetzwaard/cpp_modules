/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/03 13:47:24 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/03 16:37:41 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <deque>
# include <iostream>
# include <list>
# include <vector>

template <typename T>
typename T::iterator	easyfind(T &container, int value)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::runtime_error("value not found");
	return (it);
}

template <typename T>
typename T::const_iterator	easyfind(const T	&container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::runtime_error("value not found");
	return (it);
}

#endif