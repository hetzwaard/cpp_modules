/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/04 09:20:41 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/05 12:40:08 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <algorithm>
# include <limits>
# include <iostream>
# include <cstdlib>
# include <ctime>

class Span
{
private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;
public:
	Span(unsigned int n);
	Span(const Span &other);
	Span	&operator=(const Span &other);
	~Span();

	void	addNumber(int n);

	template <typename InputIterator>
	void	addNumbers(InputIterator first, InputIterator last)
	{
		while (first != last)
		{
			addNumber(*first);
			++first;
		}
	}

	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	class FullSpanException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
	
	class NoSpanException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
};

#endif
