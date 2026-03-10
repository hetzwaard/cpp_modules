/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/09 23:03:31 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/09 23:03:31 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>
# include <sstream>
# include <stdexcept>

class RPN
{
private:
	std::stack<double>	_stack;
public:
	RPN() = default;
	RPN(const RPN& other) = default;
	RPN& operator=(const RPN& other) = default;
	~RPN() = default;

	double	evaluate(const std::string &expression);
};

#endif