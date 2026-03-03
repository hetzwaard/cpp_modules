/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/03 13:47:06 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/03 14:19:56 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
static void	printResult(const T &container, int target, const std::string &label)
{
	try
	{
		typename T::const_iterator	it = easyfind(container, target);
		std::cout << label << ": found " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << label << ": " << e.what() << std::endl;
	}
}

static void	printTest(std::string	input)
{
	std::cout << "=== " << input << " ===" << std::endl;
}

int	main(void)
{
	std::vector<int>		vec;
	std::list<int>			lst;
	std::deque<int>		deq;

	printTest("PUSHING VALUES TO THE STACK");
	
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	lst.push_back(40);
	lst.push_back(50);
	lst.push_back(60);
	deq.push_back(70);
	deq.push_back(80);
	deq.push_back(90);

	printTest("PRINTING THE RESULTS");
	
	printResult(vec, 10, "vector hit");
	printResult(vec, 20, "vector hit");
	printResult(vec, 31, "vector miss");
	printResult(lst, 40, "list hit");
	printResult(lst, 50, "list hit");
	printResult(lst, 60, "list hit");
	printResult(deq, 75, "deque miss");
	printResult(lst, 85, "deque miss");
	printResult(lst, 95, "deque miss");
	
	// printTest("TRYING TO USE THE CONST VERSION OF IT");
	
	// const std::vector<int>	constVec(vec.begin(), vec.end());
	
	return (0);
}
