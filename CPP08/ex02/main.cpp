
#include "MutanStack.hpp"
#include <iostream>

int main() {
    MutanStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;  // Affiche 17
    mstack.pop();
    std::cout << mstack.size() << std::endl; // Affiche 1
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Parcourir avec itérateurs
    MutanStack<int>::iterator it = mstack.begin();
    MutanStack<int>::iterator ite = mstack.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    return 0;
}
