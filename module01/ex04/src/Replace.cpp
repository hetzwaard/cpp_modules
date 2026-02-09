/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Replace.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/09 17:16:22 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/09 17:16:24 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Replace.hpp"

std::string	replace_all(const std::string& input, const std::string& s1, const std::string& s2)
{
	std::string	result;
	std::size_t	pos = 0;

	result.reserve(input.size());
	while (true)
	{
		std::size_t found = input.find(s1, pos);
		if (found == std::string::npos)
		{
			result.append(input, pos, std::string::npos);
			break ;
		}
		result.append(input, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
	}
	return (result);
}
