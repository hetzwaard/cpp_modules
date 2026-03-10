/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/09 23:03:48 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/09 23:03:48 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

double	RPN::evaluate(const std::string &expression)
{
	std::istringstream	iss(expression);
	std::string				token;

	while (iss >> token)
	{
		if (token.length() == 1 && std::isdigit(token[0]))
			_stack.push(token[0] - '0');

		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error");

			double	right = _stack.top(); _stack.pop();
			double	left = _stack.top(); _stack.pop();

			if (token == "+")			_stack.push(left + right);
			else if (token == "-")	_stack.push(left - right);
			else if (token == "*")	_stack.push(left * right);
			else if (token == "/")
			{
				if (right == 0)
					throw std::runtime_error("Error");
				_stack.push(left / right);
			}
		}

		else
			throw std::runtime_error("Error");
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error");

	double	result = _stack.top();
	_stack.pop();

	return (result);
}
