/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string _name;
		u_int32_t	_HP;
		u_int32_t	_MP;
		u_int32_t _atkDmg;
		std::string _target;
	public:
		// Constructors
		ClapTrap();
		ClapTrap( std::string name );
		// Canonical Orthodox Form
		ClapTrap( const ClapTrap &copy );
		ClapTrap &operator=(const ClapTrap &other);
		// Destructor
		~ClapTrap();
		// Public methods
		void	attack( const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif