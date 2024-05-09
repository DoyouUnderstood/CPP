#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed(float number) {
    this->fixed_value = roundf(number * 256.0f);
}

Fixed::Fixed(int number) {
    this->fixed_value = number << 8;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->fixed_value) / 256.0f;
}

int Fixed::toInt(void) const {
    return this->fixed_value >> 8;
}

#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    return os << f.toFloat();
}

#include <string>
#include <iostream>

int main( void ) 
{
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}