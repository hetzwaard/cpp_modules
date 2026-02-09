/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/09 22:56:55 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/09 22:57:21 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int	main(void)
{
	Harl harl;

	std::cout << "[ DEBUG ]" << std::endl;
	harl.complain("DEBUG");

	std::cout << "[ INFO ]" << std::endl;
	harl.complain("INFO");

	std::cout << "[ WARNING ]" << std::endl;
	harl.complain("WARNING");

	std::cout << "[ ERROR ]" << std::endl;
	harl.complain("ERROR");

	std::cout << "[ UNKNOWN ]" << std::endl;
	harl.complain("NOPE");
	return (0);
}
