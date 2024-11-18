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

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	protected:
		std::string	_type;
		Brain 		*_brain;
	public:
		// Constructor
		Cat();
		Cat( std::string );
		
		// Destructor
		~Cat();
		
		// Orthodox Canonical Form
		Cat( const Cat &other );
		Cat			&operator=( const Cat &other );
		
		// Public methods
		void		makeSound() const;
		void		compare( const Cat &other );
		
		// Getter
		std::string	getType() const;
		std::string	getIdeas(int index) const;
		Brain		*getBrain() const;

		// Setter
		void		setIdeas(std::string ideas, int iterator);
};

#endif