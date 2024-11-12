/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat: public Animal
{
	protected:
		std::string _type;
	public:
		// Constructor
		Cat();
		Cat( std::string );
		// Destructor
		~Cat();
		// Orthodox Canonical Form
		Cat( const Cat &other );
		Cat &operator=( const Cat &other );
		// Public methods
		void makeSound() const;
		// Getter
		std::string getType();
};

#endif