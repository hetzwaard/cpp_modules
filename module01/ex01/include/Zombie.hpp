/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/07 18:54:54 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/07 18:58:57 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

class Zombie
{
private:
	std::string nameZombie;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void	announce(void);
	void	setName(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
