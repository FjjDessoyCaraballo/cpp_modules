/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat(): _type("cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat( std::string type ): _type(type)
{
	std::cout << "Cat named constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat( const Cat &other )
{
	this->_type = other._type;
}

Cat &Cat::operator=( const Cat &other )
{
	this->_type = other._type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meowwww" << std::endl;
}

std::string Cat::getType()
{

	return (this->_type);
}