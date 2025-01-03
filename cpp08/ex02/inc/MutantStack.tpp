/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : _stack(nullptr), _size(0), _capacity(0)
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	delete [] _stack;
}

template <typename T>
MutantStack<T>::MutantStack( const MutantStack& ref ): _size(ref._size), _capacity(ref._capacity)
{
	this->_stack = new T[_capacity];
	for (size_t i = 0; i < _size; ++i)
		this->_stack[i] = ref._stack[i];
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=( const MutantStack& ref )
{
	if (this == &ref)
		return (*this);
	delete[] this->_stack;
	this->_capacity = ref._capacity;
	this->_size = ref._size;
	this->_stack = new T[_capacity];
	for (size_t i = 0; i < _size; ++i)
		this->_stack[i] = ref._stack[i];
	return (*this);
}

template <typename T>
void MutantStack<T>::push( int num )
{
	if (this->_size == this->_capacity)
	{
		if (_capacity == 0)
			_capacity = 1;
		else
			_capacity *= 2;
		T* newStack = new T[_capacity];
		for (size_t i = 0; i < _size; ++i)
			newStack[i] = _stack[i];
		delete [] _stack;
		_stack = newStack; 
	}
	_stack[_size++] = num;
}

template <typename T>
void MutantStack<T>::pop()
{
	if (_size == 0)
		throw std::out_of_range("Stack is empty");
	--_size;
}

template <typename T>
T& MutantStack<T>::top()
{
	if (_size == 0)
		throw std::out_of_range("Stack is empty");
	return (_stack[_size - 1]);	
}

template <typename T>
size_t MutantStack<T>::size() const
{
	return (_size);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() const
{
	return (_stack);

}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() const
{
	return (_stack + _size);
}