#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#include <iostream>
#include <string>
#include <stack>

template <typename T>
class MutanStack : public std::stack<T>
{
    public : 
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }
};

#endif