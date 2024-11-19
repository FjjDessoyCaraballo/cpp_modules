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

#include "AMateria.hpp"

class Ice
{
	protected:
		std::string _type;
	public:
		// constructor
		Ice();

		// destructor
		~Ice();
		
		// Canonical Orthodox Form
		Ice( const Ice& ref );
		Ice &operator=( const Ice& ref );
		
		// public methods
		void use(ICharacter& target);
};