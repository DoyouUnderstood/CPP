#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <vector>
#include <stack>

class RPN {
public:
    static int evaluate(const std::string& expression);

private:
    static std::vector<std::string> tokenize(const std::string& expression);
    static void processToken(const std::string& token, std::stack<int>& stack);
    static bool isOperator(char c);
    static int applyOperator(char op, int left, int right);
};

#endif 