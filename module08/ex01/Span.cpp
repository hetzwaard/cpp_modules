/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/04 09:20:31 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/04 09:43:33 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n), _numbers()
{
	_numbers.reserve(_maxSize);
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int n)
{
	if (_numbers.size() >= _maxSize)
		throw FullSpanException();
	_numbers.push_back(n);
}

unsigned int	Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	std::vector<int>	sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());
	unsigned int		shortest = std::numeric_limits<unsigned int>::max();
	for (std::vector<int>::size_type i = 1; i < sorted.size(); ++i)
	{
		unsigned int diff = static_cast<unsigned int>(static_cast<long>(sorted[i]) - static_cast<long>(sorted[i - 1]));
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
}

unsigned int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());
	return (static_cast<unsigned int>(static_cast<long>(*maxIt) - static_cast<long>(*minIt)));
}

const char	*Span::FullSpanException::what() const throw()
{
	return ("Span is full");
}

const char	*Span::NoSpanException::what() const throw()
{
	return ("Not enough numbers to find a span");
}
