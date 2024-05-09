#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
    private:
        int fixed_value;
        static const int fractional_bits = 8;

    public:
        Fixed() : fixed_value(0) 
        {
            std::cout << "Default constructor called" << std::endl;
        }

        Fixed(const Fixed& other) : fixed_value(other.fixed_value) 
        {
            std::cout << "Copy constructor called" << std::endl;
        }

        Fixed& operator=(const Fixed& other) 
        {
            std::cout << "Copy assignment operator called" << std::endl;
            if (this != &other) {
                this->fixed_value = other.fixed_value;
            }
            return *this;
        }

        ~Fixed() {
            std::cout << "Destructor called" << std::endl;
        }

        int getRawBits(void) const 
        {
            std::cout << "getRawBits member function called" << std::endl;
            return this->fixed_value;
        }

        void setRawBits(int const raw) {
            this->fixed_value = raw;
        }
        Fixed (float number);
        Fixed (int number);
        float toFloat(void) const;
        int toInt(void) const;

};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif                  