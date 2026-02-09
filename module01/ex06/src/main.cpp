/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/09 23:02:50 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/09 23:02:51 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}

	Harl harl;
	harl.complain(av[1]);
	return (0);
}
