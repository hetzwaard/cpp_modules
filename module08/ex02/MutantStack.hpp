/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/05 09:30:21 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/05 09:46:04 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>
# include <iostream>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	using	Base = std::stack<T, Container>;
	using	iterator = typename Base::container_type::iterator;
	using	const_iterator = typename Base::container_type::const_iterator;
	using	reverse_iterator = typename Base::container_type::reverse_iterator;
	using	const_reverse_iterator = typename Base::container_type::const_reverse_iterator;

	iterator				begin() { return this->c.begin(); }
	iterator				end() { return this->c.end(); }
	const_iterator			begin() const { return this->c.begin(); }
	const_iterator			end() const { return this->c.end(); }

	reverse_iterator		rbegin() { return this->c.rbegin(); }
	reverse_iterator		rend() { return this->c.rend(); }
	const_reverse_iterator	rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator	rend() const { return this->c.rend(); }
};

#endif