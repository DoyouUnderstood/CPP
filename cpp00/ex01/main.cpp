#include "phonebook.hpp"

void add_contact()
{
    int i = 0;
    std::string line;
    while (i < 5)
    {
        std::getline(std::cin, line);
        
        i++;
    }
}
int main(int argc, char **argv)
{
    Phonebook repertoire;
    (void)argc;
    (void)argv;
    std::cout << "le repertoire est vide, saisir ADD, SEARCH ou EXIT";
    std::string line;
    while (line != "EXIT")
    {
        std::getline(std::cin, line);
        if (line == "ADD")
            add_contact();
    }
}