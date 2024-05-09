#include "Zombie.hpp"

int main() {
    int N = 5;
    std::string zombieName = "Walker";
    Zombie* horde = zombieHorde(N, zombieName);

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    delete[] horde;  // Libération de la mémoire allouée pour la horde
    return 0;
}

    