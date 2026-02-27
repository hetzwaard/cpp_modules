/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/27 18:49:16 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/27 19:00:19 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

int	main(void)
{
	Data	data;

	data.id = 42;
	data.name = "mahkilic";

	Data *original = &data;
	uintptr_t raw = Serializer::serialize(original);
	Data *restored = Serializer::deserialize(raw);

	std::cout << "original: " << original << std::endl;
	std::cout << "raw: " << raw << std::endl;
	std::cout << "restored " << restored << std::endl;
	std::cout << "equal " << (original == restored) << std::endl;
	std::cout << "data: " << restored->id << ", " << restored->name << std::endl;

	return (0);
}
