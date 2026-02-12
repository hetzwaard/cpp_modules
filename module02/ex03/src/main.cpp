/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/11 19:19:43 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/12 15:33:21 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"
#include <iostream>

int main(void)
{
	Point const	a(0.0f, 0.0f);
	Point const	b(10.0f, 0.0f);
	Point const	c(0.0f, 10.0f);

	Point const	inside(1.0f, 1.0f);
	Point const	outside(10.0f, 10.0f);
	Point const	on_edge(0.0f, 5.0f);
	Point const	on_vertex(0.0f, 0.0f);

	std::cout << "inside: " << bsp(a, b, c, inside) << std::endl;
	std::cout << "outside: " << bsp(a, b, c, outside) << std::endl;
	std::cout << "on edge: " << bsp(a, b, c, on_edge) << std::endl;
	std::cout << "on vertex: " << bsp(a, b, c, on_vertex) << std::endl;

	return (0);
}
