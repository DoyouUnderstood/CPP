#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {
private:
    std::map<std::string, double>  _btcDatabase;
    double findClosestRate(const std::string &date) const;
    void processExchange(const std::string &date, const double value) const;
    void parseLine(const std::string &line) const;

public:
    class Error : public std::exception {
        private:
            std::string _msg;
        public:
            Error(const std::string& msg) : _msg(msg) {}
            virtual const char* what() const throw() { return _msg.c_str(); }
            virtual ~Error() throw() {}
    };

    BitcoinExchange();
    ~BitcoinExchange();
    
    // Étape 1: Charger la base de données
    void loadDatabase(const std::string &filename);
    
    // Étape 2: Traiter le fichier d'entrée
    void processInput(const std::string &filename);
    
    // Fonctions de validation
    void isValidDate(std::string &date) const;
    void isValidValue(const double value) const;
};

#endif
