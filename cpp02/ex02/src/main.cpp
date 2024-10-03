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

int main(void)
{
    // constructors
    Fixed a;                    // Default constructor
    Fixed b(10);                 // Integer constructor
    Fixed c(42.42f);             // Float constructor
    Fixed d(b);                  // Copy constructor

    // assignment operator
    a = Fixed(1234.4321f);       // Copy assignment operator

    // output values
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    // integer and float conversions
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    // comparison operators
    std::cout << (a > b) << " (a > b)" << std::endl;
    std::cout << (a < c) << " (a < c)" << std::endl;
    std::cout << (b == d) << " (b == d)" << std::endl;
    std::cout << (b != a) << " (b != a)" << std::endl;

    // arithmetic operators
    Fixed sum = b + c;
    Fixed diff = c - b;
    Fixed mul = b * c;
    Fixed div = c / b;

    std::cout << "Sum of b and c: " << sum << std::endl;
    std::cout << "Difference between c and b: " << diff << std::endl;
    std::cout << "Multiplication of b and c: " << mul << std::endl;
    std::cout << "Division of c by b: " << div << std::endl;

    // pre-increment and post-increment
    std::cout << "Pre-increment of a: " << ++a << std::endl;
    std::cout << "Post-increment of a: " << a++ << std::endl;
    std::cout << "After post-increment, a is: " << a << std::endl;

    std::cout << "Pre-decrement of b: " << --b << std::endl;
    std::cout << "Post-decrement of b: " << b-- << std::endl;
    std::cout << "After post-decrement, b is: " << b << std::endl;

    // max and Min functions
    std::cout << "Max between a and b: " << Fixed::max(a, b) << std::endl;
    std::cout << "Min between a and b: " << Fixed::min(a, b) << std::endl;

    return 0;
}
