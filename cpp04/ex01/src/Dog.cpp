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

Dog::Dog(): _type("Dog")
{
	this->_type = "Dog";
	this->_brain = new Brain;
	std::cout << "Dog default constructor called" << std::endl;
}


Dog::Dog(const Dog &other)
{
    this->_type = other._type;
    this->_brain = new Brain(*other._brain);
    std::cout << "Dog copy constructor called" << std::endl;
}


Dog::~Dog()
{
	delete this->_brain;
	this->_brain = nullptr;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &other)
{
	if (this == &other)
		return (*this);
	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	this->_type = other._type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "WOOF WOOF!" << std::endl;
}

std::string Dog::getType() const
{
	return (this->_type);
}

Brain	*Dog::getBrain() const
{
	return (this->_brain);
}

void	Dog::compare( const Dog &other )
{
	std::cout << std::endl;
	std::cout << "This Dog brain is (heap): " << static_cast<void*>(this->_brain) << std::endl;
	std::cout << "Other Dog brain is (heap): " << static_cast<void*>(other.getBrain()) << std::endl;
	std::cout << std::endl;
}


