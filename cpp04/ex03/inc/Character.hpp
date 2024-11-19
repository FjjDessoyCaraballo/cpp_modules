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
#include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		AMateria	*(_inventory[4]);
		std::string	name;
	public:
		// constructor
		Character( std::string name );
		
		// destructor
		~Character();
		
		// canonical orthodox form
		Character( const Character& ref );
		Character &operator=( const Character& ref);
		
		// getters
		std::string const& getName() const;
		
		// setters
		
		// public methods
		void		equip(AMateria *stuff);
		void		unequip(int index);
		void		use(int index, ICharacter& target);
		AMateria	*getFromInventory(int index);
};