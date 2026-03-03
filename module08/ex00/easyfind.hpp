/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/03 13:47:24 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/03 13:47:24 by mahkilic      ########   odam.nl         */
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

class	ValueNotFound : public std::exception
{
public:
	const char	*what() const noexcept override
	{
		return "value not found";
	}
};

template <typename T>
typename T::iterator	easyfind(T &container, int value)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw ValueNotFound();
	return (it);
}

template <typename T>
typename T::const_iterator	easyfind(const T	&container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw ValueNotFound();
	return (it);
}

#endif