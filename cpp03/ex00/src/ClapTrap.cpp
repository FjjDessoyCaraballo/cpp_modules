/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::~ClapTrap()
{
}

void	ClapTrap::attack( const std::string &target )
{
	std::cout << this->_Name << " attacked " << target << " for " << this->_atkDmg << " amount of damage" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->_Name << " was hit for " << amount << " damage!" << std::endl;
	this->_HP -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << this->_Name << " repaired " << amount << " worth of damage" << std::endl;
	this->_HP += amount;
}