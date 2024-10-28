/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	private:
		bool		_guard;
	public:
		//Constructors
		ScavTrap();
		ScavTrap( std::string name );

		// Canonical Orthodox Form
		ScavTrap( const ScavTrap &copy );
		ScavTrap &operator=( const ScavTrap &other );
		
		// Destructor
		~ScavTrap();
		
		// Methods
		void	attack( const std::string &target );
		void	guardGate();
};

#endif