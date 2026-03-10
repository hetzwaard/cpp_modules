/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/09 23:55:52 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/09 23:55:52 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const std::vector<int>	&PmergeMe::getVector() const { return (_vec); }
const std::deque<int>	&PmergeMe::getDeque() const { return (_deq); }

void	PmergeMe::parseInput(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::string	arg(av[i]);
		std::size_t	pos;
		int			num;

		try
		{
			num = std::stoi(arg, &pos);
		}
		catch (...)
		{
			throw std::runtime_error("Error");
		}
		if (pos != arg.size())
			throw std::runtime_error("Error");
		if (num <= 0)
			throw std::runtime_error("Error");

		_vec.push_back(num);
		_deq.push_back(num);
	}
}

static std::vector<int>	getJacobsthalOrder(int n)
{
	if (n <= 0)
		return std::vector<int>();

	std::vector<int>	jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	while (jacobsthal.back() < n)
	{
		std::size_t sz = jacobsthal.size();
		jacobsthal.push_back(jacobsthal[sz - 1] + 2 * jacobsthal[sz - 2]);
	}

	std::vector<int>	order;
	std::vector<bool>	used(n + 1, false);

	for (std::size_t i = 2; i < jacobsthal.size(); i++)
	{
		int	hi = std::min(jacobsthal[i], n);
		int	lo = jacobsthal[i - 1];
		for (int j = hi; j > lo; j--)
		{
			if (!used[j])
			{
				order.push_back(j);
				used[j] = true;
			}
		}
	}

	for (int j = 1; j <= n; j++)
	{
		if (!used[j])
			order.push_back(j);
	}

	return (order);
}

static void	fjVecRecurse(std::vector<int> &vec, int groupSize)
{
	int	n = vec.size();
	int	pairCount = n / (groupSize * 2);

	if (pairCount < 1)
		return;

	for (int i = 0; i < pairCount; i++)
	{
		int	leftStart = i * groupSize * 2;
		int	rightStart = leftStart + groupSize;

		if (vec[leftStart + groupSize - 1] > vec[rightStart + groupSize - 1])
		{
			for (int j = 0; j < groupSize; j++)
				std::swap(vec[leftStart + j], vec[rightStart + j]);
		}
	}

	fjVecRecurse(vec, groupSize * 2);

	std::vector<int>	mainChain;
	std::vector<std::vector<int> >	pendGroups;

	std::vector<std::vector<int> >	winners;
	std::vector<std::vector<int> >	losers;

	for (int i = 0; i < pairCount; i++)
	{
		int	base = i * groupSize * 2;
		std::vector<int>	loser(vec.begin() + base, vec.begin() + base + groupSize);
		std::vector<int>	winner(vec.begin() + base + groupSize, vec.begin() + base + groupSize * 2);
		losers.push_back(loser);
		winners.push_back(winner);
	}

	for (int j = 0; j < groupSize; j++)
		mainChain.push_back(losers[0][j]);
	for (std::size_t i = 0; i < winners.size(); i++)
		for (int j = 0; j < groupSize; j++)
			mainChain.push_back(winners[i][j]);

	for (std::size_t i = 1; i < losers.size(); i++)
		pendGroups.push_back(losers[i]);

	int	remaining = n - pairCount * groupSize * 2;
	if (remaining >= groupSize)
	{
		int	base = pairCount * groupSize * 2;
		std::vector<int>	strag(vec.begin() + base, vec.begin() + base + groupSize);
		pendGroups.push_back(strag);
	}

	std::vector<int>	insertOrder = getJacobsthalOrder(pendGroups.size());

	for (std::size_t i = 0; i < insertOrder.size(); i++)
	{
		std::vector<int>	&group = pendGroups[insertOrder[i] - 1];
		int	key = group[groupSize - 1];

		int	lo = 0;
		int	hi = (int)(mainChain.size() / groupSize);
		while (lo < hi)
		{
			int	mid = (lo + hi) / 2;
			if (mainChain[mid * groupSize + groupSize - 1] < key)
				lo = mid + 1;
			else
				hi = mid;
		}

		mainChain.insert(mainChain.begin() + lo * groupSize, group.begin(), group.end());
	}

	for (std::size_t i = 0; i < mainChain.size() && i < (std::size_t)n; i++)
		vec[i] = mainChain[i];
}

void	PmergeMe::sortVector()
{
	fjVecRecurse(_vec, 1);
}


static void	fjDeqRecurse(std::deque<int> &deq, int groupSize)
{
	int	n = deq.size();
	int	pairCount = n / (groupSize * 2);

	if (pairCount < 1)
		return;

	for (int i = 0; i < pairCount; i++)
	{
		int	leftStart = i * groupSize * 2;
		int	rightStart = leftStart + groupSize;
		if (deq[leftStart + groupSize - 1] > deq[rightStart + groupSize - 1])
		{
			for (int j = 0; j < groupSize; j++)
				std::swap(deq[leftStart + j], deq[rightStart + j]);
		}
	}

	fjDeqRecurse(deq, groupSize * 2);

	std::deque<int>	mainChain;
	std::vector<std::deque<int> >	pendGroups;

	std::vector<std::deque<int> >	winners;
	std::vector<std::deque<int> >	losers;

	for (int i = 0; i < pairCount; i++)
	{
		int	base = i * groupSize * 2;
		std::deque<int>	loser(deq.begin() + base, deq.begin() + base + groupSize);
		std::deque<int>	winner(deq.begin() + base + groupSize, deq.begin() + base + groupSize * 2);
		losers.push_back(loser);
		winners.push_back(winner);
	}

	for (int j = 0; j < groupSize; j++)
		mainChain.push_back(losers[0][j]);
	for (std::size_t i = 0; i < winners.size(); i++)
		for (int j = 0; j < groupSize; j++)
			mainChain.push_back(winners[i][j]);

	for (std::size_t i = 1; i < losers.size(); i++)
	{
		std::deque<int>	tmp(losers[i].begin(), losers[i].end());
		pendGroups.push_back(tmp);
	}

	int	remaining = n - pairCount * groupSize * 2;
	if (remaining >= groupSize)
	{
		int	base = pairCount * groupSize * 2;
		std::deque<int>	strag(deq.begin() + base, deq.begin() + base + groupSize);
		pendGroups.push_back(strag);
	}

	std::vector<int>	insertOrder = getJacobsthalOrder(pendGroups.size());

	for (std::size_t i = 0; i < insertOrder.size(); i++)
	{
		std::deque<int>	&group = pendGroups[insertOrder[i] - 1];
		int	key = group[groupSize - 1];

		int	lo = 0;
		int	hi = (int)(mainChain.size() / groupSize);
		while (lo < hi)
		{
			int	mid = (lo + hi) / 2;
			if (mainChain[mid * groupSize + groupSize - 1] < key)
				lo = mid + 1;
			else
				hi = mid;
		}

		mainChain.insert(mainChain.begin() + lo * groupSize, group.begin(), group.end());
	}

	for (std::size_t i = 0; i < mainChain.size() && i < (std::size_t)n; i++)
		deq[i] = mainChain[i];
}

void	PmergeMe::sortDeque()
{
	fjDeqRecurse(_deq, 1);
}

void	PmergeMe::run()
{
	std::cout << "Before:";
	for (std::size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	auto	startVec = std::chrono::high_resolution_clock::now();
	sortVector();
	auto	endVec = std::chrono::high_resolution_clock::now();
	double	timeVec = std::chrono::duration<double, std::micro>(endVec - startVec).count();

	auto	startDeq = std::chrono::high_resolution_clock::now();
	sortDeque();
	auto	endDeq = std::chrono::high_resolution_clock::now();
	double	timeDeq = std::chrono::duration<double, std::micro>(endDeq - startDeq).count();

	std::cout << "After:";
	for (std::size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque  : " << timeDeq << " us" << std::endl;
}