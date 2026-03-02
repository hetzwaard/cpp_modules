/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/02 12:10:08 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/02 12:17:59 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void	printElement(const T &value)
{
	std::cout << value << std::endl;
}

void	increment(int &value)
{
	++value;
}

int	main(void)
{
	int					numbers[] = {1, 2, 3, 4, 5};
	const std::string	words[] = {"hello", "template", "iter"};

	std::cout << "numbers before increment:" << std::endl;
	iter(numbers, 5, printElement<int>);

	iter(numbers, 5, increment);

	std::cout << "numbers after increment:" << std::endl;
	iter(numbers, 5, printElement<int>);

	std::cout << "const words:" << std::endl;
	iter(words, 3, printElement<std::string>);

	return (0);
}
