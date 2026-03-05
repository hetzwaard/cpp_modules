/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/05 09:30:10 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/05 12:40:37 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "forward:\n";
	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "const forward\n";
	const MutantStack<int>	constStack = mstack;
	MutantStack<int>::const_iterator	cit = constStack.begin();
	MutantStack<int>::const_iterator	cite = constStack.end();
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}

	std::cout << "reverse:\n";
	MutantStack<int>::reverse_iterator	rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator	rite = mstack.rend();
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	std::stack<int>	s(mstack);
	std::cout << "copied to std::stack top: " << s.top() << std::endl;

	return (0);
}

//int main()
//{
//	MutantStack<int> mstack;

//	mstack.push(5);
//	mstack.push(17);

//	std::cout << mstack.top() << std::endl;
//	mstack.pop();
//	std::cout << mstack.size() << std::endl;

//	mstack.push(3);
//	mstack.push(5);
//	mstack.push(737);
//	//[...]
//	mstack.push(0);
//	MutantStack<int>::iterator it = mstack.begin();
//	MutantStack<int>::iterator ite = mstack.end();
//	++it;
//	--it;
//	while (it != ite)
//	{
//		std::cout << *it << std::endl;
//		++it;
//	}
//	std::stack<int> s(mstack);
//	return 0;
//}
