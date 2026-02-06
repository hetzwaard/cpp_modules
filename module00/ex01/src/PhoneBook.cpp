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
	std::cout << "|       EXIT   ➔ to exit the phonebook         |" << std::endl;
	std::cout << "|                                              |" << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━▼▲━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl;
}

void	PhoneBook::start()
{
	std::string	input;
	count = 0;
	nextIndex = 0;
	while (1)
	{
		PhoneBook::menu();
		std::cout << std::endl;
		std::cout << "Enter a command: ";
		std::getline(std::cin, input);
		if (!std::cin)
		{
			std::cout << std::endl << "Input closed. Exiting PhoneBook." << std::endl;
			exit (EXIT_SUCCESS);
		}
		if (input == "ADD")
		{
			PhoneBook::addContact();
		}
		else if (input == "SEARCH")
		{
			PhoneBook::searchContact();
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

int	PhoneBook::parseIndex(std::string input, bool &valid)
{
	if (input.empty())
	{
		valid = false;
		return (-1);
	}
	for (size_t i = 0; i < input.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
		{
			valid = false;
			return (-1);
		}
	}
	std::stringstream	ss(input);
	int					index;
	ss >> index;
	if (ss.fail())
	{
		valid = false;
		return (-1);
	}
	valid = true;
	return (index);
}


static bool	isBlank(const std::string &str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!std::isspace(static_cast<unsigned char>(str[i])))
			return (false);
	}
	return (true);
}

static bool	readNonEmptyField(const std::string &label, std::string &out)
{
	std::cout << label;
	std::getline(std::cin, out);
	if (!std::cin)
		return (false);
	while (isBlank(out))
	{
		std::cout << label << " cannot be empty. Please enter again." << std::endl;
		std::cout << label;
		std::getline(std::cin, out);
		if (!std::cin)
			return (false);
	}
	return (true);
}

void	PhoneBook::addContact()
{
	std::string	input;
	if (!readNonEmptyField("First Name: ", input))
		return ;
	contacts[nextIndex].setFirstName(input);
	if (!readNonEmptyField("Last Name: ", input))
		return ;
	contacts[nextIndex].setLastName(input);
	if (!readNonEmptyField("Nickname: ", input))
		return ;
	contacts[nextIndex].setNickName(input);
	if (!readNonEmptyField("Phone Number: ", input))
		return ;
	contacts[nextIndex].setPhoneNumber(input);
	if (!readNonEmptyField("Darkest Secret: ", input))
		return ;
	contacts[nextIndex].setDarkestSecret(input);
	std::cout << "Contact has been succesfully saved!" << std::endl;
	if (count < 8)
		count++;
	nextIndex = (nextIndex + 1) % 8;
}

std::string	PhoneBook::formatString(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::searchContact()
{
	std::string	input;
	int			searchIndex;
	bool			valid;

	if (count == 0)
	{
		std::cout << "No contacts available. Please add a contact first." << std::endl;
		return ;
	}
	searchIndex = 0;
	std::cout << "Available contacts:" << std::endl;
	std::cout << "|" << std::setw(10) << "Index"
				 << "|" << std::setw(10) << "First Name"
				 << "|" << std::setw(10) << "Last Name"
				 << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << "|" << std::setw(10) << (i + 1)
					 << "|" << std::setw(10) << PhoneBook::formatString(contacts[i].getFirstName())
					 << "|" << std::setw(10) << PhoneBook::formatString(contacts[i].getLastName())
					 << "|" << std::setw(10) << PhoneBook::formatString(contacts[i].getNickName())
					 << "|" << std::endl;
	}
	std::cout << "Enter the index of the contact to view details: ";
	std::getline(std::cin, input);
	searchIndex = PhoneBook::parseIndex(input, valid);
	if (!valid || searchIndex < 1 || searchIndex > count)
	{
		std::cout << "Invalid index. Please try again." << std::endl;
		return ;
	}
	searchIndex -= 1;
	std::cout << "Contact Details:" << std::endl;
	std::cout << "First Name: " << contacts[searchIndex].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[searchIndex].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[searchIndex].getNickName() << std::endl;
	std::cout << "Phone Number: " << contacts[searchIndex].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[searchIndex].getDarkestSecret() << std::endl;
}
