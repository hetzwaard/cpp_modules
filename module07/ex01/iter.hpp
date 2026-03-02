/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/02 12:10:14 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/02 12:14:20 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
# include <iostream>
# include <string>

template <typename T, typename F>
void	iter(T *array, std::size_t len, F func)
{
	std::size_t	i = 0;

	while (i < len)
	{
		func(array[i]);
		++i;
	}
}

template <typename T, typename F>
void	iter(const T *array, std::size_t len, F func)
{
	std::size_t	i = 0;

	while (i < len)
	{
		func(array[i]);
		++i;
	}
}

#endif