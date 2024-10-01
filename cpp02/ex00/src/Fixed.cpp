/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed( void ): _fpn(0)
{
	std::cout << "Default contructor called" << std::endl;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &other): _fpn(other._fpn)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_fpn = other._fpn;
	}
	return (*this);
}

int	Fixed::getRawBits ( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fpn);
}

void	Fixed::setRawBits ( int const raw )
{
	_fpn = raw;
}