/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/02 12:22:28 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/02 12:53:20 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>
# include <string>

template <typename T>
class	Array
{
private:
	T				*_data;
	unsigned int	_size;

public:
	Array(void);
	Array(unsigned int n);
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array(void);

	class	OutOfBoundsException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	T				&operator[](unsigned int index);
	const T			&operator[](unsigned int index) const;
	unsigned int	size(void) const;
};

template <typename T>
Array<T>::Array(void) : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(n)
{
	if (_size > 0)
		_data = new T[_size]();
}

template <typename T>
Array<T>::Array(const Array &other) : _data(NULL), _size(other._size)
{
	if (_size > 0)
	{
		_data = new T[_size]();
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = other._data[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		T	*new_data = NULL;
	
		if (other._size > 0)
		{
			new_data = new T[other._size]();
			try
			{
				for (unsigned int i = 0; i < other._size; ++i)
					new_data[i] = other._data[i];
			}
			catch (...)
			{
				delete[] new_data;
				throw;
			}
		}
		delete[] _data;
		_data = new_data;
		_size = other._size;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] _data;
}

template <typename T>
const char	*Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Array index out of bounds");
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return (_data[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return (_data[index]);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (_size);
}

#endif