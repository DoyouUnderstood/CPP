#include "Zombie.hpp"
#include <iostream>

int main() {
    int N = 5;
    Zombie* horde = zombieHorde(N, "HordeZombie");

    if (horde) {
        for (int i = 0; i < N; ++i) {
            horde[i].announce();
        }
        delete[] horde;
    } else {
        std::cerr << "Failed to create horde" << std::endl;
    }

    return 0;
}
