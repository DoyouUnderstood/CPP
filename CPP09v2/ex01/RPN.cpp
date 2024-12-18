#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

bool RPN::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isNumber(const std::string& token) const {
    if (token.empty() || token.length() > 1) 
        return false;
    return token[0] >= '0' && token[0] <= '9';
}

void RPN::performOperation(const std::string& op) {
    if (_stack.size() < 2) {
        throw InvalidExpressionError("Error: not enough operands");
    }

    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();

    if (op == "+") _stack.push(a + b);
    else if (op == "-") _stack.push(a - b);
    else if (op == "*") _stack.push(a * b);
    else if (op == "/") {
        if (b == 0) throw InvalidExpressionError("Error: division by zero");
        _stack.push(a / b);
    }
}

int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token.find_first_of("()") != std::string::npos) {
            throw InvalidExpressionError("Error: parentheses not allowed");
        }

        if (isNumber(token)) {
            _stack.push(token[0] - '0');
        }
        else if (isOperator(token)) {
            performOperation(token);
        }
        else {
            throw InvalidExpressionError("Error: invalid token");
        }
    }

    if (_stack.size() != 1) {
        throw InvalidExpressionError("Error: invalid expression");
    }

    return _stack.top();
}
