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

#include <stack>
#include <stdexcept>
#include <sstream>

class Rpn
{
	private:
		// constructor
		Rpn();

		// destructor
		~Rpn();

		// canonical form
		Rpn( const Rpn& ref );
		Rpn& operator=( const Rpn& ref );
	public:
		// public methods
		static int	outputResult( std::string equation );
};