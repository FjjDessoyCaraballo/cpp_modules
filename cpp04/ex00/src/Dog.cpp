/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog(): _type("dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog( std::string type ): _type(type)
{
	std::cout << "Dog named constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog( const Dog &other )
{
	this->_type = other._type;
}

Dog &Dog::operator=( const Dog &other )
{
	this->_type = other._type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "WOOF WOOF!" << std::endl;
}

std::string Dog::getType()
{
	return (this->_type);
}