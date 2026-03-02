/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/02 12:21:56 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/02 13:05:36 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
void	printArray(const Array<T> &arr, const std::string &name)
{
	std::cout << name << " (size=" << arr.size() << "):";

	for (unsigned int i = 0; i < arr.size(); ++i)
		std::cout << " " << arr[i];
	std::cout << std::endl;
}

void	printTest(std::string input)
{
	std::cout << "=== " << input << " ===" << std::endl;
}

int	main(void)
{
	printTest("ARRAY TEST #1");
	Array<int>	empty;
	std::cout << "empty.size() = " << empty.size() << std::endl;

	printTest("ARRAY TEST #2");
	Array<int> a(5);
	printArray(a, "a default");

	printTest("ARRAY TEST #3");
	for (unsigned int i = 0; i < a.size(); ++i)
		a[i] = static_cast<int>(i * 10);
	printArray(a, "a filled");

	printTest("ARRAY TEST #4");
	Array<int> b(a);
	a[0] = 999;
	std::cout << "after changing a[0]:" << std::endl;
	printArray(a, "a");
	printArray(b, "b copy");

	printTest("ARRAY TEST #5");
	Array<int> c;
	c = a;
	a[1] = 777;
	std::cout << "after assignment + changing a[1]:" << std::endl;
	printArray(a, "a");
	printArray(c, "c assigned");

	printTest("EXCEPTION TEST");
	try
	{
		std::cout << a[5] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
	
	printTest("ARRAY TEST #6");
	const Array<int> const_arr(b);
	std::cout << "const_arr[2] = " << const_arr[2] << std::endl;

	Array<std::string> words(3);
	words[0] = "hello";
	words[1] = "hola";
	words[2] = "merhaba";
	printArray(words, "words");

	return (0);
}