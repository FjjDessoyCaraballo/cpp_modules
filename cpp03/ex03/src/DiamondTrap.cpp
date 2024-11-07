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

DiamondTrap::DiamondTrap(): ClapTrap("defaultDiamondTrap_clap_trap")
{
	this->_name = "defaultDiamondTrap";
	std::cout << "DiamondTrap default constructor called: " << this->_name << std::endl;
	this->_HP = FragTrap::_HP;
	this->_MP = ScavTrap::_MP;
	this->_atkDmg = FragTrap::_atkDmg;
}

DiamondTrap::DiamondTrap( const DiamondTrap &other ): ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap"), ScavTrap(name), FragTrap(name), _name(name)
{
	this->_name = "defaultDiamondTrap";
	this->_HP = FragTrap::_HP;
	this->_MP = ScavTrap::_MP;
	this->_atkDmg = FragTrap::_atkDmg;
	std::cout << "DiamondTrap named constructor called: " << this->_name << std::endl;
}

// Destructor

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called: " << this->_name << std::endl;
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
	std::cout << "Am I " << this->_name << " or " << ClapTrap::_name << "?" << std::endl;
}