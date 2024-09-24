/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie::Zombie( std::string name ): _Name(name)
{
}
Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << Zombie::_Name << std::endl;
}

void Zombie::announce()
{
	std::cout << Zombie::_Name << ": BraiiiiiiinnnzzzZ... " << std::endl;
}

void Zombie::zombieName(std::string name)
{
	this->_Name = name;
}