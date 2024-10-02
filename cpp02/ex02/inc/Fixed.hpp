/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> // for roundf

class Fixed
{
	private:
		int 				_fpn; // Fixed Pointer Number
		static const int 	_il = 8; // Integer Literal
	public:
		Fixed( void );
		Fixed( const Fixed &other );
		Fixed &operator=(const Fixed &other);
		~Fixed( void );
		Fixed ( const int nbr );
		Fixed ( const float nbr );

		// getters
		int		getRawBits ( void ) const;
		float	toFloat( void ) const;
		int		toInt( void ) const;

		// setters
		void	setRawBits ( int const raw );
};

std::ostream	&operator<<(std::ostream &other, Fixed const &nbr);

#endif