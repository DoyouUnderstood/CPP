#ifndef SEDREPLACE_HPP
#define SEDREPLACE_HPP

#include <string>

class SedReplace {
public:
    SedReplace(const std::string& filename, const std::string& s1, const std::string& s2);
    bool replace();

private:
    std::string filename;
    std::string s1;
    std::string s2;

    bool readFile(std::string& content) const;
    void writeFile(const std::string& content) const;
    std::string replaceOccurrences(const std::string& content) const;
};

#endif
