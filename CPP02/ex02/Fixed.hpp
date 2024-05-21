#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int                 value;  // Stocke la valeur du nombre en virgule fixe
    static const int    fractionalBits = 8;  // Nombre de bits pour la partie fractionnaire

public:
    Fixed();  // Constructeur par défaut
    Fixed(const int intValue);  // Constructeur prenant un entier
    Fixed(const float floatValue);  // Constructeur prenant un flottant
    Fixed(const Fixed& other);  // Constructeur de recopie
    Fixed& operator=(const Fixed& other);  // Opérateur d'affectation
    ~Fixed();  // Destructeur

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;  // Convertit en flottant
    int toInt(void) const;  // Convertit en entier

    // Surcharger les opérateurs de comparaison
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Surcharger les opérateurs arithmétiques
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Surcharger les opérateurs d'incrémentation et de décrémentation
    Fixed& operator++();  // Pré-incrémentation
    Fixed operator++(int);  // Post-incrémentation
    Fixed& operator--();  // Pré-décrémentation
    Fixed operator--(int);  // Post-décrémentation

    // Fonctions membres statiques
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    // Surcharge de l'opérateur d'insertion pour afficher la valeur en virgule flottante
    friend std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
};

#endif
