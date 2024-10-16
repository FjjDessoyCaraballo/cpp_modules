/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

// Constructors

DiamondTrap::DiamondTrap(): ScavTrap(), FragTrap(),
{
	std::cout << "DiamondTrap constructor called" << _name << std::endl;
	this->_HP = FragTrap::_HP;
	this->_MP = 100;
	this->_atkDmg = 30;
}

DiamondTrap::DiamondTrap( const DiamondTrap &other ): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name): _name(name)
{
	std::cout << _name << " has joined the battle!" << std::endl;
}

// Destructor

DiamondTrap::~DiamondTrap()
{
	std::cout << _name << std::endl;
}

// Overloaded operators

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &other )
{
	std::cout << "DiamondTrap assignament operator called" << std::endl;
	this->_HP = other._HP;
	this->_MP = other._MP;
	this->_atkDmg = other._atkDmg;
	return (*this);
}

// Public methods

void	DiamondTrap::whoAmI()
{
	std::cout << "Am I " << this->_name << " or " << (here we are going to declare claptrap name) << "?" << std::endl;
}

