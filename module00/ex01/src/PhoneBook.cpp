/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/04 15:12:13 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/04 19:06:56 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

void	PhoneBook::start()
{
	std::cout << "Welcome to your PhoneBook!" << std::endl;
	std::cout << "You can use the following commands:" << std::endl;
	std::cout << "ADD - to add a new contact" << std::endl;
	std::cout << "SEARCH - to search for a contact" << std::endl;
	std::cout << "EXIT - to exit the program" <<  std::endl;
}

void	PhoneBook::getCommand()
{
	std::string	command;
	int index = 1;
	while (1)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			PhoneBook::addContact(index);
		}
		else if (command == "SEARCH")
		{
			PhoneBook::searchContact(index);
		}
		else if (command == "EXIT")
		{
			std::cout << "Exiting PhoneBook. Goodbye!" << std::endl;
			exit (EXIT_SUCCESS);
		}
		else
		{
			std::cout << "Invalid command. Please try again." << std::endl;
			continue;
		}
	}
}

void	PhoneBook::addContact(int &index)
{
	std::string	input;

	if (index >= 8)
	{
		std::cout << "PhoneBook is full. Overwriting the oldest contact." << std::endl;
		index = 0;
	}
	std::cout << "First Name: ";
	std::getline(std::cin, input);
	contacts[index].setFirstName(input);
	std::cout << "Last Name: ";
	std::getline(std::cin, input);
	contacts[index].setLastName(input);
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	contacts[index].setNickName(input);
	std::cout << "Phone Number: ";
	std::getline(std::cin, input);
	contacts[index].setPhoneNumber(input);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, input);
	contacts[index].setDarkestSecret(input);
	if (index < 8)
		index++;
}

void	PhoneBook::searchContact(int index)
{
	std::string	input;
	int			searchIndex;

	if (index < 1)
	{
		std::cout << "No contacts available. Please add a contact first." << std::endl;
		return ;
	}
	searchIndex = 0;
	std::cout << "Available contacts:" << std::endl;
	for (int i = 0; i < index && i < 8; i++)
	{
		std::cout << i << ": " << contacts[i].getFirstName() << " " << contacts[i].getLastName() << std::endl;
	}
	std::cout << "Enter the index of the contact to view details: ";
	std::getline(std::cin, input);
	searchIndex = std::stoi(input);
	if (searchIndex < 0 || searchIndex >= index || searchIndex >= 8)
	{
		std::cout << "Invalid index. Please try again." << std::endl;
		return ;
	}
	std::cout << "Contact Details:" << std::endl;
	std::cout << "First Name: " << contacts[searchIndex].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[searchIndex].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[searchIndex].getNickName() << std::endl;
	std::cout << "Phone Number: " << contacts[searchIndex].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[searchIndex].getDarkestSecret() << std::endl;
}
