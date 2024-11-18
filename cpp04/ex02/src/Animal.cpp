/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal( std::string type ): _type(type)
{
	std::cout << "Animal named constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal( const Animal &other )
{
	this->_type = other._type;
}

Animal &Animal::operator=( const Animal &other )
{
	this->_type = other._type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Standard animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return (this->_type);
}