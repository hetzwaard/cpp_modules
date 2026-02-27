/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/27 19:14:32 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/27 19:24:09 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"

int	main(void)
{
	Base	*ptr;
	int		i;

	std::srand(static_cast<unsigned int>(std::time(NULL)));

	i = 0;
	while (i < 10)
	{
		ptr = generate();

		std::cout << "identify(Base*): ";
		identify(ptr);

		std::cout << "identify(Base&): ";
		identify(*ptr);

		delete ptr;
		++i;
	}
	return (0);
}
