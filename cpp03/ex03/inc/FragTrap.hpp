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
		std::string	_name;
		u_int32_t	_HP;
		u_int32_t	_MP;
		u_int32_t	_atkDmg;
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
		// getter
		int32_t	getHp();
};

#endif