/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

// Constructors

/** INHERITANCE
 * 
 * 
 * 
 */
ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap constructor called" << _Name << std::endl;
	this->_HP = 100;
	this->_MP = 50;
	this->_atkDmg = 20;
	this->_guardGate = false;
}

ScavTrap::ScavTrap( const ScavTrap &copy ): ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->_guardGate = copy._guardGate;
}

ScavTrap::ScavTrap( std::string name): _Name(name)
{
	std::cout << _Name << " has joined the battle!" << std::endl;
}

// Destructor

ScavTrap::~ScavTrap()
{
	std::cout << _Name << std::endl;
}

// Overloaded operators

ScavTrap &ScavTrap::operator=( const ScavTrap &other )
{
	std::cout << "ScavTrap assignament operator called" << std::endl;
	this->_HP = other._HP;
	this->_MP = other._MP;
	this->_atkDmg = other._atkDmg;
	this->_guardGate = other._guardGate;
	return (*this);
}

// Public methods

void	ScavTrap::attack( const std::string &target )
{
	std::cout << this->_Name << " attacked " << target << " for " << this->_atkDmg << " amount of damage" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->_guardGate == false)
	{
		this->_guardGate = true;
		std::cout << _Name << " is now on guard mode!" << std::endl;
	}
	else
		std::cout << _Name << " is already guarding the gates!" << std::endl;
}
