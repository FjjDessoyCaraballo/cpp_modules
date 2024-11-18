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
#include <string>

class Brain
{
	private:
		std::string		_ideas[100];
	public:
		// Constructor
		Brain();
		
		// Destructor
		~Brain();
		
		// Canonical Orthodox Form
		Brain( const Brain &other );
		Brain			&operator=( const Brain &other );
		
		// Getters
		std::string		getIdeas(int index) const;

		// Setters
		// Public methods
};