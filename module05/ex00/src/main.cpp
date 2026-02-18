/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/18 00:34:06 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/18 14:53:06 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int	main(void)
{
	std::cout << "=== Valid case ===" << std::endl;
	try
	{
		Bureaucrat	a("Joe", 2);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Low bound case ===" << std::endl;
	try
	{
		Bureaucrat	b("Bob", 149);
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Invalid constructor case ===" << std::endl;
	try
	{
		Bureaucrat	c("TooHigh", 0);
		std::cout << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception for grade 0: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Invalid constructor case ===" << std::endl;
	try
	{
		Bureaucrat	d("TooLow", 151);
		std::cout << d << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception for grade 151: " << e.what() << std::endl;
	}

	return (0);
}
