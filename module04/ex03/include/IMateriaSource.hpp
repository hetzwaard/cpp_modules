/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   IMateriaSource.hpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/16 17:40:34 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/16 17:40:34 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_H
# define IMATERIASOURCE_H

# include <string>

class AMateria;

class IMateriaSource
{
public:
	virtual ~IMateriaSource();
	virtual void		learnMateria(AMateria *m) = 0;
	virtual AMateria	*createMateria(std::string const &type) = 0;
};

#endif
