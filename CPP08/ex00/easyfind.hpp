#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end()) {
        throw std::out_of_range("La valeur n'a pas ete trouve dans le conteneur.");
    }
    
    return it;
}

#endif
