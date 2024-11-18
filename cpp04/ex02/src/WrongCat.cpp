/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat( std::string type ): _type(type)
{
	std::cout << "WrongCat named constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat &other )
{
	this->_type = other._type;
}

WrongCat &WrongCat::operator=( const WrongCat &other )
{
	this->_type = other._type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "WOOF! Wait..." << std::endl;
}

std::string	WrongCat::getType() const
{
	return (_type);
}