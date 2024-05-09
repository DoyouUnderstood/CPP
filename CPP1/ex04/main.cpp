#include <iostream>
#include <fstream>
#include <string>

void replaceAndWrite(std::istream& in, std::ostream& out, const std::string& s1, const std::string& s2) 
{
    std::string line;
    while (std::getline(in, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        out << line << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error: Could not open input file " << filename << std::endl;
        return 1;
    }

    std::ofstream outputFile(filename + ".replace");
    if (!outputFile) {
        std::cerr << "Error: Could not open output file " << filename + ".replace" << std::endl;
        return 1;
    }

    replaceAndWrite(inputFile, outputFile, s1, s2);

    inputFile.close();
    outputFile.close();

    return 0;
}
