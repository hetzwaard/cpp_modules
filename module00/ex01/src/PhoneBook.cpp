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

void	PhoneBook::menu()
{
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━▲▼━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
	std::cout << "|                                              |" << std::endl;
	std::cout << "|                 DE PHONEBOOK                 |" << std::endl;
	std::cout << "|                                              |" << std::endl;
	std::cout << "|       You can use a following command:       |" << std::endl;
	std::cout << "|                                              |" << std::endl;
	std::cout << "|       ADD    ➔ to add a new contact          |" << std::endl;
	std::cout << "|       SEARCH ➔ to search for a contact       |" << std::endl;
	std::cout << "|       EXIT   ➔ to exit the phonebook         |" <<  std::endl;
	std::cout << "|                                              |" << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━▼▲━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl;
}

void	PhoneBook::start()
{
	std::string	input;
	int index = 1;
	while (1)
	{
		PhoneBook::menu();
		std::cout << "" << std::endl;
		std::cout << "Enter a command: ";
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			PhoneBook::addContact(index);
		}
		else if (input == "SEARCH")
		{
			PhoneBook::searchContact(index);
		}
		else if (input == "EXIT")
		{
			std::cout << "Exiting PhoneBook. Goodbye!" << std::endl;
			exit (EXIT_SUCCESS);
		}
		else
		{
			std::cout << "Invalid input. Please try again." << std::endl;
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
		index = 1;
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
	std::cout << "Contact has been succesfully saved!" << std::endl;
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
	searchIndex = 1;
	std::cout << "Available contacts:" << std::endl;
	for (int i = 1; i < index && i <= 8; i++)
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
