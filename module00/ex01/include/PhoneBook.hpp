/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/04 15:10:53 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/04 18:52:22 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <cctype>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
public:
	void	menu();
	void	start();
	void	addContact(int &index);
	void	searchContact(int index);
};

#endif