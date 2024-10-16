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

//Constructors

ClapTrap::ClapTrap()
{
	std::cout << "Constructor for " << _name << " called" <<std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other )
{
	std::cout << "Copy constructor for " << _name << " called" <<std::endl;
	*this = other;
}

ClapTrap::ClapTrap( std::string name ): _name(name), _HP(10), _MP(10), _atkDmg(0)
{
}

// Destructor

ClapTrap::~ClapTrap()
{
	std::cout << _name << std::endl;
}

// Overloaded Operator

ClapTrap	&ClapTrap::operator=( const ClapTrap &other)
{
	std::cout << "ClapTrap assignament operator called" << std::endl;
	this->_name = other._name;
	this->_HP = other._HP;
	this->_MP = other._MP;
	this->_atkDmg = other._atkDmg;
	return (*this);
}

// Public methods

void	ClapTrap::attack( const std::string &target )
{
	if (this->_HP > 0 && this->_MP > 0)
	{
		std::cout << this->_name << " attacked " << target << " for " << this->_atkDmg << " points of damage" << std::endl;
		this->_MP--;
	}
	else if (this->_MP == 0)
		std::cout << this->_name << " can't attack " << target << " because it has no energy!" << std::endl;
	else
		std::cout << this->_name << " can't attack " << target << " because it has no hitpoints!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_HP > amount)
		this->_HP -= amount;
	else if (this->_HP > 0)
		this->_HP = 0;
	else
	{
		std::cout << _name << " is already dead!" << std::endl;
	}
	std::cout << this->_name << " was hit for " << amount << " damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_MP > 0 && this->_HP > 0 && this->_HP + amount <= 10)
	{	
		this->_HP += amount;
		std::cout << this->_name << " repaired " << amount << " worth of HP" << std::endl;
		this->_MP--;
	}
	else if (this->_MP == 0)
		std::cout << _name << " has no energy to repair itself!" << std::endl;
	else if (this->_HP == 0)
		std::cout << _name << " is dead and cannot repair itself!" << std::endl;
	else
		std::cout << _name << " is already at max health!" << std::endl;
}