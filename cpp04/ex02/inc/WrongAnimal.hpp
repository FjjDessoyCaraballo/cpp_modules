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

class WrongAnimal
{
	private:
		std::string _type;
	public:
		// constructors
		WrongAnimal();
		WrongAnimal( std::string type );
		// destructors
		~WrongAnimal();

		// canonical orthodox form
		WrongAnimal( const WrongAnimal &other );
		WrongAnimal &operator=( const WrongAnimal &other );

		// getters
		std::string getType() const;

		// Public methods
		void makeSound() const;
};
