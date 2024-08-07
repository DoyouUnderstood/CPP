#include "Base.hpp"
#include "generate.hpp"
#include "identify.hpp"
#include <iostream>

int main() {
    Base* p = generate();
    identify(p);
    identify(*p);
    delete p;

    return 0;
}
