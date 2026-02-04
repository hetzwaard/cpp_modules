/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/04 15:10:36 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/04 18:38:37 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;

	phoneBook.start();
	phoneBook.getCommand();
	return (0);
}
