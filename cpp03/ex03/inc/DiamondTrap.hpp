/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: virtual public ScavTrap, virtual public FragTrap
{
	private:
		std::string	_name;
	public:
		// constructors
		DiamondTrap();
		DiamondTrap( std::string name );
		
		// canonical form
		DiamondTrap( const DiamondTrap &other );
		DiamondTrap &operator=( const DiamondTrap &other );
		
		// destructor
		~DiamondTrap();
		
		// public methods
		void	whoAmI();
};

#endif