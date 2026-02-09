/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/09 16:56:00 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/09 22:01:44 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Replace.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	const std::string	filename = av[1];
	const std::string	s1 = av[2];
	const std::string	s2 = av[3];

	if (s1.empty())
	{
		std::cerr << "Error: s1 must not be empty" << std::endl;
		return (1);
	}

	std::ifstream	in(filename.c_str());
	if (!in)
	{
		std::cerr << "Error: cannot open input file" << std::endl;
		return (1);
	}

	std::string	content((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
	in.close();

	std::ofstream	out((filename + ".replace").c_str());
	if (!out)
	{
		std::cerr << "Error: cannot open output file" << std::endl;
		return (1);
	}

	out << replace_all(content, s1, s2);
	return (0);
}
