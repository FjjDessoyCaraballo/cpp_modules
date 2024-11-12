/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog: public Animal
{
	protected:
		std::string _type;
	public:
		// Constructor
		Dog();
		Dog( std::string );
		// Destructor
		~Dog();
		// Orthodox Canonical Form
		Dog( const Dog &other );
		Dog &operator=( const Dog &other );
		// Public methods
		void makeSound() const;
		// Getter
		std::string getType();
};

#endif