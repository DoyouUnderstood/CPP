#include "SedReplace.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be an empty string." << std::endl;
        return 1;
    }

    SedReplace sedReplace(filename, s1, s2);
    if (!sedReplace.replace()) {
        std::cerr << "Error: replacement failed." << std::endl;
        return 1;
    }

    return 0;
}
