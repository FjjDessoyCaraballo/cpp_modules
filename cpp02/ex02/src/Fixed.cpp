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

/**
 * #### Constructors and destructor
 */
Fixed::Fixed( void ): _fpn(0)
{
	std::cout << "Default contructor called" << std::endl;
}

Fixed::Fixed( const int nbr )
{
	std::cout << "Int constructor called" << std::endl;
	this->_fpn = nbr << this->_il;

}

Fixed::Fixed( const float nbr )
{
	std::cout << "Float constructor called" << std::endl;
	this->_fpn = std::roundf(nbr * (1 << this->_il));
}


Fixed::Fixed( const Fixed &other): _fpn(other._fpn)
{
	std::cout << "Copy constructor called" << std::endl;
	Fixed::operator=(other);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

/**
 * #### Public methods
 */
int	Fixed::getRawBits ( void ) const
{
	return (_fpn);
}

void	Fixed::setRawBits ( int const raw )
{
	_fpn = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_fpn / (float)(1 << this->_il));
}

/**
 * What the hell is this doing? Short answer is bitwise shift operation
 * Ok, what the hell? Simple. Lets assume that we're going to convert 
 * the number `42.42` to simple decimal notation (not float):
 * 
 * 
 * #### Convert Float to Fixed-Point Representation:

	1. Assume _il is the number of fractional bits, let's say _il = 8 for this example.

	2. Multiply the float by (2^{_il}) to convert it to a fixed-point number;
	3. For `42.42`: [ \text{fixed-point} = 42.42 \times 2^8 = 42.42 \times 256 = 10842.24 ];
	4. The fixed-point representation is stored as an integer, so
	it would be `10842` (rounding down).
	
 * #### Store Fixed-Point Value:

	1. _fpn will store the integer value 10842.

 * #### Convert Fixed-Point to Integer:
	1. Use the toInt method which shifts the bits to the right by _il positions.
	2. For 10842: [ \text{integer} = 10842 \gg 8 = \frac{10842}{256} = 42 ].

 * #### Original Float to Fixed-Point:

	1. Float: `42.42`;
	2. Fixed-Point (with _il = 8): [ 42.42 \times 256 = 10842 ];

 * #### Fixed-Point Representation in Binary:

	1. 10842 in binary: 0010101000111010.

 * #### Bitwise Right Shift:

	1. Shifting 10842 (0010101000111010) right by 8 bits:
	2. Original: 0010101000111010
	3. Shifted: 0000000000101010 (which is 42 in decimal)

 * #### Conclusion:

	1. Float: `42.42`
	2. Fixed-Point: `10842` (stored in _fpn)
	3. Binary Fixed-Point: `0010101000111010`
	3. After Right Shift: `0000000000101010` (`42` in decimal)
  */
int		Fixed::toInt( void ) const
{
	return (this->_fpn >> this->_il);
}

/**
 * ### Operators overloading
 * 
 * To overload an operator means to specify what exactly that operator
 * will do. In a way, it costumizes what it does. In our case here, we
 * are simply giving it the value of whatever is given at getRawBits(),
 * which only returns the private variable _fpn for internal use.
 * 
 * The second overload operation is taking care of the output `<<`
 * , therefore the return value is `std::ostream&`. After we insert this
 * overload method in our class, we get to use the output in main().
 */
Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_fpn = other.getRawBits();
	}
	return (*this);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed ret_value(*this);

	ret_value._fpn += other._fpn;
	return (ret_value);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed ret_value(*this);

	ret_value._fpn -= other._fpn;
	return (ret_value);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed	ret_value(*this);
	int		value;

	value = (ret_value._fpn / other._fpn) * (1 << _il);
	ret_value.setRawBits(value);
	return (ret_value);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed	ret_value(*this);
	int		value;

	value = (ret_value._fpn * other._fpn) / (1 << _il);
	ret_value.setRawBits(value);
	return (ret_value);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed ret_value(*this);

	
	return (ret_value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_fpn == other._fpn);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_fpn != other._fpn);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_fpn >= other._fpn);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_fpn <= other._fpn);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_fpn > other._fpn);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_fpn < other._fpn);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a > b)
		return (b);
	return (a);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (b);
	return (a);
}
// preincrementation
Fixed Fixed::operator++()
{
	this->_fpn++;
	return (*this);
}

Fixed Fixed::operator--()
{
	this->_fpn--;
	return (*this);
}

// postincrementation
Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;

	this->_fpn++;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;

	this->_fpn--;
	return (tmp);
}

std::ostream	&operator<<(std::ostream &other, Fixed const &fix)
{
	other << fix.toFloat();
	return (other);
}
