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

class Fixed
{
	private:
		int 				_fpn;
		static const int 	_il = 8;
	public:
		Fixed( void );
		Fixed( const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed( void );

		// getters
		int		getRawBits ( void ) const;

		// setters
		void	setRawBits ( int const raw );
};

#endif