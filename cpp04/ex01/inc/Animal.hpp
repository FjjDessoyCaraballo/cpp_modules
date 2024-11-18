/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		// Constructor
		Animal();
		Animal( std::string );
		// Destructor
		virtual ~Animal();
		// Orthodox Canonical Form
		Animal( const Animal &other );
		Animal &operator=( const Animal &other );
		// Public methods
		virtual void makeSound() const;
		// Getter
		std::string getType() const;
};

#endif