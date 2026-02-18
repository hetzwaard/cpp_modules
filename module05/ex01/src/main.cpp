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
#include "../include/Form.hpp"

int	main(void)
{
	std::cout << "=== Form creation ===" << std::endl;
	try
	{
		Form	a("TaxForm", 50, 20);
		std::cout << a << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Invalid form grades ===" << std::endl;
	try
	{
		Form	b("BadHigh", 0, 50);
		std::cout << b << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception for grade 0: " << e.what() << std::endl;
	}

	try
	{
		Form	c("BadLow", 151, 50);
		std::cout << c << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception for grade 151: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Signing tests ===" << std::endl;
	try
	{
		Bureaucrat	low("LowRank", 100);
		Bureaucrat	high("HighRank", 20);
		Form		permit("PermitA", 50, 30);

		std::cout << low << std::endl;
		std::cout << high << std::endl;
		std::cout << permit << std::endl;

		low.signForm(permit);
		std::cout << permit << std::endl;
		high.signForm(permit);
		std::cout << permit << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
	return (0);
}
