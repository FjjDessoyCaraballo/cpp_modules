/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/WrongAAnimal.hpp"

WrongAAnimal::WrongAAnimal()
{
	std::cout << "WrongAAnimal default constructor called" << std::endl;
}

WrongAAnimal::~WrongAAnimal()
{
	std::cout << "WrongAAnimal destructor called" << std::endl;
}

WrongAAnimal::WrongAAnimal( std::string type ): _type(type)
{
	std::cout << "WrongAAnimal named constructor called" << std::endl;
}

WrongAAnimal::WrongAAnimal( const WrongAAnimal &other )
{
	this->_type = other._type;
}

WrongAAnimal &WrongAAnimal::operator=( const WrongAAnimal &other )
{
	this->_type = other._type;
	return (*this);
}

void	WrongAAnimal::makeSound() const
{
	std::cout << "WrongAAnimal standard sound" << std::endl;
}

std::string	WrongAAnimal::getType() const
{
	return (_type);
}