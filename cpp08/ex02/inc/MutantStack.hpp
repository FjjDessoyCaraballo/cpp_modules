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

template <typename T>
class MutantStack
{
	private:
		T*		_stack;
	public:
		//constructors
		MutantStack();

		// destructor
		~MutantStack();

		// canonical  form
		MutantStack( const MutantStack& ref );
		MutantStack &operator=( const MutantStack& ref );

		// public methods
		void	push( int num );
		void	pop( int num );
		int		begin();
		int		end();

		//exceptions
};

#include "MutantStack.tpp"