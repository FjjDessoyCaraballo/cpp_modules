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
		~Fixed( void );
		Fixed ( const int nbr );
		Fixed ( const float nbr );

		// getters
		int		getRawBits ( void ) const;
		float	toFloat( void ) const;
		int		toInt( void ) const;

		// setters
		void	setRawBits ( int const raw );

				// OPERATORS
		// arithmetic operators
		Fixed &operator=(const Fixed &other);
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		// logical operators
		bool operator<=(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>(const Fixed &other) const;
				// INCREMENTS
		// preincrementation

		//postincrementation

				// MIN MAX
		Fixed &max(Fixed &a, Fixed &b);
		Fixed &min(Fixed &a, Fixed &b);
		const Fixed &max(const Fixed &a, const Fixed &b);
		const Fixed &min(const Fixed &a, const Fixed &b);

};

std::ostream	&operator<<(std::ostream &other, Fixed const &nbr);

#endif