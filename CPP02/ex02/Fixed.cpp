#include "Fixed.hpp"

// Constructeur par défaut
Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructeur prenant un entier
Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    this->value = intValue << fractionalBits;  // Décale les bits de l'entier vers la gauche
}

// Constructeur prenant un flottant
Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    this->value = static_cast<int>(roundf(floatValue * (1 << fractionalBits)));
}

// Constructeur de recopie
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Opérateur d'affectation
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->value = other.getRawBits();
    }
    return *this;
}

// Destructeur
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Retourne la valeur brute
int Fixed::getRawBits(void) const {
    return this->value;
}

// Initialise la valeur brute
void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

// Convertit la valeur en virgule fixe en flottant
float Fixed::toFloat(void) const {
    return static_cast<float>(this->value) / (1 << fractionalBits);
}

// Convertit la valeur en virgule fixe en entier
int Fixed::toInt(void) const {
    return this->value >> fractionalBits;
}

// Surcharge de l'opérateur d'insertion
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}

// Surcharger les opérateurs de comparaison
bool Fixed::operator>(const Fixed& other) const {
    return this->value > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const {
    return this->value < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->value >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->value <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
    return this->value == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->value != other.getRawBits();
}

// Surcharger les opérateurs arithmétiques
Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.getRawBits() == 0) {
        throw std::runtime_error("Division by zero");
    }
    return Fixed(this->toFloat() / other.toFloat());
}

// Surcharger les opérateurs d'incrémentation et de décrémentation
Fixed& Fixed::operator++() {
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}

// Fonctions membres statiques
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}
