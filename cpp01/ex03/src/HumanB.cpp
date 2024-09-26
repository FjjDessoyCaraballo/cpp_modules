/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB()
{	
}

HumanB::~HumanB()
{
}

HumanB::HumanB( std::string name ): _Name(name), _Weap(nullptr)
{
}
/**
 * This is a setter function, we need a getter if we want to output
 * the message in the attack() function.
 */
void	HumanB::setWeapon( Weapon &Weapon )
{
	this->_Weap = &Weapon;
}

std::string	HumanB::getWeapon()
{
	if (!this->_Weap)
		return ("mighty stick");
	return (_Weap->getType());
}

void	HumanB::attack()
{
	std::cout << this->_Name << " attacks with their " << getWeapon() << std::endl;
}