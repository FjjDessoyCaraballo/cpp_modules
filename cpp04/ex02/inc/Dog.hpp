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

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
	protected:
		Brain		*_brain;
		std::string	_type;
	public:
		// Constructor
		Dog();
		Dog( std::string );
		
		// Destructor
		~Dog();
		
		// Orthodox Canonical Form
		Dog( const Dog &other );
		Dog 		&operator=( const Dog &other );
		
		// Public methods
		void		makeSound() const;
		void		compare( const Dog &other );

		// Getter
		std::string	getType() const;
		std::string	getIdeas(int index) const;
		Brain		*getBrain() const;


		// Setter
};

#endif