#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cctype>

std::vector<std::string> RPN::tokenize(const std::string& expression) {
    std::vector<std::string> tokens;
    std::istringstream stream(expression);
    std::string token;
    while (stream >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

bool RPN::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::applyOperator(char op, int left, int right) {
    switch (op) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/':
            if (right == 0) throw std::runtime_error("Error: division by zero.");
            return left / right;
        default:
            throw std::runtime_error("Error: invalid operator.");
    }
}

void RPN::processToken(const std::string& token, std::stack<int>& stack) {
    if (token.size() == 1 && isOperator(token[0])) {
        if (stack.size() < 2) {
            throw std::runtime_error("Error: insufficient operands.");
        }
        int right = stack.top(); stack.pop();
        int left = stack.top(); stack.pop();
        stack.push(applyOperator(token[0], left, right));
    } else if (std::isdigit(token[0])) {
        stack.push(std::stoi(token));
    } else {
        throw std::runtime_error("Error: invalid token.");
    }
}

int RPN::evaluate(const std::string& expression) {
    std::vector<std::string> tokens = tokenize(expression);
    std::stack<int> stack;

    for (std::vector<std::string>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
        processToken(*it, stack);
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Error: invalid expression.");
    }

    return stack.top();
}