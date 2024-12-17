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

#include "Data.h"
#include <iostream>
#include <cstdint>

class Serializer
{
	private:
		// constructor
		Serializer();

		// destructor
		~Serializer();
	public:
		// canonical form
		Serializer( const Serializer& ref );
		Serializer &operator=( const Serializer& ref );

		// public methods
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

