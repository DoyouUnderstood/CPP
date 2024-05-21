#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 value;  // Stocke la valeur du nombre en virgule fixe
    static const int    fractionalBits = 8;  // Nombre de bits pour la partie fractionnaire

public:
    Fixed();  // Constructeur par défaut
    Fixed(const Fixed& other);  // Constructeur de recopie
    Fixed& operator=(const Fixed& other);  // Opérateur d'affectation
    ~Fixed();  // Destructeur

    int getRawBits(void) const;  // Retourne la valeur brute du nombre en virgule fixe
    void setRawBits(int const raw);  // Initialise la valeur avec celle passée en paramètre
};

#endif
