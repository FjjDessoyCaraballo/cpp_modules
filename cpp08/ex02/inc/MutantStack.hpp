/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#pragma once

#include <stdexcept>
#include <deque>

template <typename T>
class MutantStack
{
	private:
		T*		_stack;
		size_t	_size;
		size_t	_capacity;
	public:
		//public typedef
		typedef T* iterator;

		// conversion operator
		operator std::deque<T>() const {
			return (std::deque<T>(this->begin(), this->end()));
		};

		//constructors
		MutantStack();

		// destructor
		~MutantStack();

		// canonical  form
		MutantStack( const MutantStack& ref );
		MutantStack &operator=( const MutantStack& ref );

		// public methods
		void			push( T num );
		void			pop();
		T&				top();
		size_t			size() const;
		bool 			empty() const;
		void		 	swap(MutantStack<T>& secondStack);
		template <typename... Args> void			emplace(Args&&... args);

		// iterators
		iterator		end() const;
		iterator		begin() const;
};

#include "MutantStack.tpp"