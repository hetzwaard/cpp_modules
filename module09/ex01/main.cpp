/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/09 23:03:22 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/09 23:03:22 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			RPN		rpn;
			double	result = rpn.evaluate(av[1]);
			std::cout << result << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			return (1);
		}
	}
	else
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	return (0);
}
