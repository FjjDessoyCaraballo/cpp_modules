/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ): _type(type)
{
	std::cout << "WrongAnimal named constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &other )
{
	this->_type = other._type;
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal &other )
{
	this->_type = other._type;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal standard sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (_type);
}