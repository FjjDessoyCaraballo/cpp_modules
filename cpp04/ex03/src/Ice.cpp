/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

Ice::Ice(): _type("ice")
{
	std::cout << "Ice is being casted!" << std::endl;
}

Ice::~Ice()
{
	std::cout << "The ice has melted!" << std::endl;
}

Ice::Ice( const Ice& ref ): _type(ref._type)
{
}

Ice &Ice::operator=( const Ice& ref )
{
	this->_type = ref._type;
	return (*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "Ice was casted on" << target << std::endl;
}