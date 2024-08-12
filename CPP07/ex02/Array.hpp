#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <array>
#include <cstddef>
#include <iostream>

template <typename T>
class Array
{
    private:
        T* elements;
        size_t len;
    public :
        Array() :  T(0), len(0) {}
        Array(unsigned int nb) : len(nb) 
        {
            if (nb > 0)
            {
                elements = new T[nb];
                for (unsigned int i = 0; i < nb; ++i) 
                {
                    elements[i] = 0;
                }
            } else {
                elements = 0;
            }
        }
        Array(Array& a) : len(a.len)
        {
            if (len > 0)
            {
                elements = new T[len];
                for (size_t i = 0; i <= len ; i++)
                    elements[i] = a.elements[i];
            }
            else 
                elements = 0;
        }
        Array& operator=(Array& a) 
        {
            len = a.len;
            if (len > 0)
            {

                elements = new T[len];
                for (unsigned int i = 0; i < len; ++i) 
                {
                    elements[i] = 0;
                }
            } else 
                elements = 0;
            return *this;
        }
        T& operator[](unsigned int index) {
            if (index >= len) {
                throw std::out_of_range("Index out of bounds");
            }
            return elements[index];
        }

        const T& operator[](unsigned int index) const {
            if (index >= len) {
                throw std::out_of_range("Index out of bounds");
            }
            return elements[index];
        }
        int size() const {
            return len;
        }
    };

#endif 