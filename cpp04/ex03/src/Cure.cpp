/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/Cure.hpp"

Cure::Cure(): _type("Cure")
{
	std::cout << "Cure is being casted!" << std::endl;
}

Cure::~Cure()
{
	std::cout << "The Cure has melted!" << std::endl;
}

Cure::Cure( const Cure& ref ): _type(ref._type)
{
}

Cure &Cure::operator=( const Cure& ref )
{
	this->_type = ref._type;
	return (*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "Cure was casted on" << target << std::endl;
}