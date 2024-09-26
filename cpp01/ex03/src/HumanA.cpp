/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

HumanA::HumanA()
{
}

HumanA::~HumanA()
{
}

HumanA::HumanA( std::string name, Weapon &Weap ): _Name(name), _Weap(&Weap)
{
}

std::string	HumanA::getWeapon()
{
	return (_Weap->getType());
}

void	HumanA::attack()
{
	std::cout << this->_Name << " attacks with their " << getWeapon() << std::endl;
}