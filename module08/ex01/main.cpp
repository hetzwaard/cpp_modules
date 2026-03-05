/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/04 09:21:04 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/05 12:42:52 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	try
	{
		Span	sp(5);
	
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	
		std::cout << "subject shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "subject longest: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "subject test error: " << e.what() << std::endl;
	}

	try
	{
		Span	small(1);
	
		small.addNumber(31);

		std::cout << small.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "no-span test: " << e.what() << std::endl;
	}

	try
	{
		Span	full(2);
	
		full.addNumber(1);
		full.addNumber(2);
		full.addNumber(3);
	}
	catch (const std::exception &e)
	{
		std::cerr << "full-span test: " << e.what() << std::endl; 
	}

	try
	{
		Span	range(6);
		int	values[] = {6, 2, 9, 15, 1, 11};

		range.addNumbers(values, values + 6);
		std::cout << "range shortest: " << range.shortestSpan() << std::endl;
		std::cout << "range longest: " << range.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "range test error: " << e.what() << std::endl;
	}

	try
	{
		Span	overflow(3);
		int	values[] = {1, 2, 3, 4};

		overflow.addNumbers(values, values + 4);
	}
	catch (const std::exception &e)
	{
		std::cerr << "range overflow test: " << e.what() << std::endl;
	}

	try
	{
		Span	big(10000);
	
		std::srand(static_cast<unsigned int>(std::time(NULL)));

		for (int i = 0; i < 10000; ++i)
			big.addNumber(std::rand());

		std::cout << "big shortest: " << big.shortestSpan() << std::endl;
		std::cout << "big longest: " << big.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "big test error: " << e.what() << std::endl;
	}

	return (0);
}
