/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/09 23:56:05 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/09 23:56:05 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <algorithm>
# include <ctime>
# include <stdexcept>
# include <sstream>

class PmergeMe
{
private:
	std::vector<int>	_vec;
	std::deque<int>	_deq;
public:
	PmergeMe() = default;
	PmergeMe(const PmergeMe& other) = default;
	PmergeMe& operator=(const PmergeMe& other) = default;
	~PmergeMe() = default;

	void	parseInput(int ac, char **av);
	void	sortVector();
	void	sortDeque();
	void	run();

	const	std::vector<int>	&getVector() const;
	const	std::deque<int>	&getDeque() const;
};

#endif