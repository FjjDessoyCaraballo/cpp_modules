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
	std::cout << "ScavTrap default constructor called: " << _name << std::endl;
	this->_HP = 100;
	this->_MP = 50;
	this->_atkDmg = 20;
	this->_guard = false;
}

ScavTrap::ScavTrap( const ScavTrap &copy ): ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->_guard = copy._guard;
}

ScavTrap::ScavTrap( std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap named Contructor called: " << _name << std::endl;
	this->_HP = 100;
	this->_MP = 50;
	this->_atkDmg = 20;
	this->_guard = false;
}

// Destructor

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor for " << _name << " called"<< std::endl;
}

// Overloaded operators

ScavTrap &ScavTrap::operator=( const ScavTrap &other )
{
	std::cout << "ScavTrap assignament operator called" << std::endl;
	this->_HP = other._HP;
	this->_MP = other._MP;
	this->_atkDmg = other._atkDmg;
	this->_guard = other._guard;
	return (*this);
}

// Public methods

void	ScavTrap::attack( const std::string &target )
{
	if (this->_HP > 0 && this->_MP > 0)
		std::cout << this->_name << " attacked " << target << " for " << this->_atkDmg << " points of damage" << std::endl;
	else if (this->_MP == 0)
		std::cout << this->_name << " can't attack " << target << " because it has no energy!" << std::endl;
	else
		std::cout << this->_name << " can't attack " << target << " because it has no hitpoints!" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->_guard == false)
	{
		this->_guard = true;
		std::cout << _name << " is now on guard mode!" << std::endl;
	}
	else
		std::cout << _name << " is already guarding the gates!" << std::endl;
}

