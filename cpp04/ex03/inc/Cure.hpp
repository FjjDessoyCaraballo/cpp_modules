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

class Cure
{
	protected:
		std::string _type;
	public:
		// constructor
		Cure();

		// destructor
		~Cure();
		
		// Canonical Orthodox Form
		Cure( const Cure& ref );
		Cure &operator=( const Cure& ref );
		
		// public methods
		void use(ICharacter& target);
};