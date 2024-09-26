/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>

class Weapon
{
	private:
		std::string _Type;
	public:
		Weapon();
		~Weapon();
		Weapon( std::string type );
		const std::string& getType();
		void setType( std::string type);
};

#endif