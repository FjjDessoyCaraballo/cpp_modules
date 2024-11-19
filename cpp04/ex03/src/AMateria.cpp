/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Materia without form was created!" << std::endl;
}
AMateria::AMateria( std::string const& type ): _type(type)
{
	std::cout << "Materia of type " << type << " created!" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Materia destroyed!" << std::endl;
}
AMateria::AMateria( const AMateria& ref )
{
	std::cout << "Materia without form was constructed from a copy" << std::endl;
	this->_type = ref._type;
}

AMateria &AMateria::operator=( const AMateria& ref )
{
	this->_type = ref._type;
	return (*this);
}

const std::string &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use( ICharacter& target ) // need to make a getter for ICharacter
{
	std::cout << "Materia without form was used on" << target << std::endl;
}