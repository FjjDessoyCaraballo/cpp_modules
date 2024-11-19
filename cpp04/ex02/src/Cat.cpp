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
	this->_type = "Cat";
	this->_brain = new Brain;
	std::cout << "Cat default constructor called" << std::endl;
}


Cat::Cat(const Cat &other): AAnimal("Cat")
{
    this->_type = other._type;
    this->_brain = new Brain(*other._brain);
    std::cout << "Cat copy constructor called" << std::endl;
}


Cat::~Cat()
{
    delete this->_brain;
    this->_brain = nullptr;
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
	if (this == &other)
		return (*this);
	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	this->_type = other._type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meowwww" << std::endl;
}

std::string Cat::getType() const
{
	return (this->_type);
}

std::string	Cat::getIdeas(int index) const
{
	return (_brain->getIdeas(index));
}

Brain	*Cat::getBrain() const
{
	return (this->_brain);
}

void	Cat::compare( const Cat &other )
{
	std::cout << "This cat brain is (heap): " << static_cast<void*>(this->_brain) << std::endl;
	std::cout << "Other cat brain is (heap): " << static_cast<void*>(other.getBrain()) << std::endl;
	std::cout << std::endl;
}


