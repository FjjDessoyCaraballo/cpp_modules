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

class WrongAAnimal
{
	private:
		std::string _type;
	public:
		// constructors
		WrongAAnimal();
		WrongAAnimal( std::string type );
		// destructors
		~WrongAAnimal();

		// canonical orthodox form
		WrongAAnimal( const WrongAAnimal &other );
		WrongAAnimal &operator=( const WrongAAnimal &other );

		// getters
		std::string getType() const;

		// Public methods
		void makeSound() const;
};
