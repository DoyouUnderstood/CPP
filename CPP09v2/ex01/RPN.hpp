#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>

class RPN {
private:
    std::stack<int> _stack;
    
    bool isOperator(const std::string& token) const;
    void performOperation(const std::string& op);
    bool isNumber(const std::string& token) const;

public:
    RPN();
    RPN(const RPN& other);
    ~RPN();
    RPN& operator=(const RPN& other);

    int evaluate(const std::string& expression);

    class InvalidExpressionError : public std::runtime_error {
        public:
            InvalidExpressionError(const std::string& msg) : std::runtime_error(msg) {}
    };
};

#endif
