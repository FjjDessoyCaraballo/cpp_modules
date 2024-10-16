/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

// Constructors

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap constructor called" << _name << std::endl;
	this->_HP = 100;
	this->_MP = 100;
	this->_atkDmg = 30;
}

FragTrap::FragTrap( const FragTrap &copy ): ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name): _name(name)
{
	std::cout << _name << " has joined the battle!" << std::endl;
}

// Destructor

FragTrap::~FragTrap()
{
	std::cout << _name << std::endl;
}

// Overloaded operators

FragTrap &FragTrap::operator=( const FragTrap &other )
{
	std::cout << "FragTrap assignament operator called" << std::endl;
	this->_HP = other._HP;
	this->_MP = other._MP;
	this->_atkDmg = other._atkDmg;
	return (*this);
}

// Public methods

void	FragTrap::highFivesGuys()
{
	if (this->_MP > 0)
	{
		std::cout << _name << " requests the highest of fives!" << std::endl;
		std::cout << "**SCHMACK!**" << std::endl;
	}
	else
		std::cout << _name << " is too exhausted to high five! ):" << std::endl;
}
