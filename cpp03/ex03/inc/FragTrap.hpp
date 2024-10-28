/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	private:
	
	public:
		// constructors
		FragTrap();
		FragTrap( std::string name );
		// canonical form
		FragTrap( const FragTrap &copy );
		FragTrap	&operator=(const FragTrap &other);
		// destructor
		~FragTrap();
		// methods
		void	highFivesGuys();
};

#endif