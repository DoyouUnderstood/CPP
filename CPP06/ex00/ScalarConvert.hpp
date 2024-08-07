#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <limits>
#include <cmath>

class ScalarConvert
{
public:
    static void convert(const std::string &str);

private:
    ScalarConvert();
    ~ScalarConvert();
    ScalarConvert(const ScalarConvert&);
    ScalarConvert& operator=(const ScalarConvert&);
};

#endif // SCALARCONVERT_HPP

