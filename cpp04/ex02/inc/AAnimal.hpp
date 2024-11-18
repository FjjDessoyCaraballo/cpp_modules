/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <iostream>

class AAnimal
{
	protected:
		std::string _type;
	public:
		// Constructor
		AAnimal();
		AAnimal( std::string );
		// Destructor
		virtual ~AAnimal();
		// Orthodox Canonical Form
		AAnimal( const AAnimal &other );
		AAnimal &operator=( const AAnimal &other );
		// Public methods
		virtual void makeSound() const;
		// Getter
		std::string getType() const;
};

#endif