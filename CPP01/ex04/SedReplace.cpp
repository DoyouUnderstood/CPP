#include "SedReplace.hpp"
#include <fstream>
#include <iostream>

SedReplace::SedReplace(const std::string& filename, const std::string& s1, const std::string& s2)
    : filename(filename), s1(s1), s2(s2) {}

bool SedReplace::replace() {
    std::string content;

    if (!readFile(content)) {
        std::cerr << "Error: could not read file " << filename << std::endl;
        return false;
    }
    std::string replacedContent = replaceOccurrences(content);
    writeFile(replacedContent);
    return true;
}

bool SedReplace::readFile(std::string& content) const {
    std::ifstream infile(filename.c_str());
    if (!infile.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(infile, line)) {
        content += line + "\n";
    }
    infile.close();
    return true;
}

void SedReplace::writeFile(const std::string& content) const {
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile.is_open()) {
        std::cerr << "Error: could not write to file " << filename << ".replace" << std::endl;
        return;
    }
    outfile << content;
    outfile.close();
}

std::string SedReplace::replaceOccurrences(const std::string& content) const {
    std::string result;
    size_t pos = 0;
    size_t startPos = 0;

    while ((pos = content.find(s1, startPos)) != std::string::npos) 
    {
        result += content.substr(startPos, pos - startPos);
        result += s2;
        startPos = pos + s1.length();
    }
    result += content.substr(startPos);
    return result;
}
