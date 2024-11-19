/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

AAnimal::AAnimal(): _type("default animal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal( std::string type ): _type(type)
{
	std::cout << "AAnimal named constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal &other )
{
	this->_type = other._type;
}

AAnimal &AAnimal::operator=( const AAnimal &other )
{
	this->_type = other._type;
	return (*this);
}

void AAnimal::makeSound() const
{
	std::cout << "Standard AAnimal sound" << std::endl;
}

std::string AAnimal::getType() const
{
	return (this->_type);
}