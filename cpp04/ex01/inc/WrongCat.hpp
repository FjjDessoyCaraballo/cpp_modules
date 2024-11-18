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
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	private:
		std::string _type;
	public:
		// constructors
		WrongCat();
		WrongCat( std::string type );
		// destructors
		~WrongCat();

		// canonical orthodox form
		WrongCat( const WrongCat &other );
		WrongCat &operator=( const WrongCat &other );

		// getters
		std::string	getType() const;

		// Public methods
		void makeSound() const;
};
