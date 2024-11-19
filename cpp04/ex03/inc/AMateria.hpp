/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
	public:
		// constructor
		AMateria();
		AMateria( std::string const& type);
		
		// destructor
		virtual ~AMateria();
		
		// canonical orthodox form
		AMateria( AMateria const& ref );
		AMateria &operator=( AMateria const& ref );

		// public methods
		const std::string& getType() const; // returns materia type
		virtual AMateria* clone() const = 0;
		virtual void use( ICharacter& target );
};