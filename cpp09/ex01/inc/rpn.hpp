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

#include <iostream>
#include <stack>
#include <sstream>

class Rpn
{
	private:
		std::stack<int64_t>	_operands;
		int64_t				_result;
	public:
		// constructor
		Rpn( std::string& equation);

		// destructor
		~Rpn();

		// canonical form
		Rpn( const Rpn& ref );
		Rpn& operator=( const Rpn& ref );

		// public methods
		void	outputResult();
		bool	isDigit( std::string nbr )

		// setters
		void	setResult( int64_t result );
		// getters
		const int64_t	getResult() const;

};