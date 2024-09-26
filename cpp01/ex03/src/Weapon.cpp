/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

Weapon::Weapon( std::string type ): _Type(type)
{
}

const std::string& Weapon::getType()
{
	return (this->_Type);
}

void Weapon::setType( std::string type )
{
	this->_Type = type;
}