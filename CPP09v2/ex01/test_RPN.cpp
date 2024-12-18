#include "RPN.hpp"
#include <iostream>
#include <cassert>
#include <string>

#define TEST_ASSERT(condition, message) \
    do { \
        std::cout << "Testing: " << message << std::endl; \
        if (!(condition)) { \
            std::cerr << "Test failed: " << message << std::endl; \
            return false; \
        } \
        std::cout << "Passed!" << std::endl; \
    } while (0)

bool test_basic_operations() {
    std::cout << "\n=== Testing Basic Operations ===" << std::endl;
    RPN rpn;
    
    // Test addition
    TEST_ASSERT(rpn.evaluate("2 3 +") == 5, "Basic addition (2 3 +)");
    
    // Reset RPN instance for next test
    rpn = RPN();
    // Test subtraction
    TEST_ASSERT(rpn.evaluate("5 3 -") == 2, "Basic subtraction (5 3 -)");
    
    rpn = RPN();
    // Test multiplication
    TEST_ASSERT(rpn.evaluate("4 2 *") == 8, "Basic multiplication (4 2 *)");
    
    rpn = RPN();
    // Test division
    TEST_ASSERT(rpn.evaluate("6 2 /") == 3, "Basic division (6 2 /)");
    
    return true;
}

bool test_complex_expressions() {
    std::cout << "\n=== Testing Complex Expressions ===" << std::endl;
    RPN rpn;
    
    // Test examples from subject
    TEST_ASSERT(rpn.evaluate("8 9 * 9 - 9 - 9 - 4 - 1 +") == 42, 
                "Complex expression (8 9 * 9 - 9 - 9 - 4 - 1 +)");
    
    rpn = RPN();
    TEST_ASSERT(rpn.evaluate("7 7 * 7 -") == 42, 
                "Complex expression (7 7 * 7 -)");
    
    rpn = RPN();
    TEST_ASSERT(rpn.evaluate("1 2 * 2 / 2 * 2 4 - +") == 0, 
                "Complex expression (1 2 * 2 / 2 * 2 4 - +)");
    
    return true;
}

bool test_error_cases() {
    std::cout << "\n=== Testing Error Cases ===" << std::endl;
    RPN rpn;
    bool caught_exception;
    
    // Test division by zero
    caught_exception = false;
    try {
        std::cout << "Testing division by zero (5 0 /)" << std::endl;
        rpn.evaluate("5 0 /");
    } catch (const RPN::InvalidExpressionError& e) {
        caught_exception = true;
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }
    TEST_ASSERT(caught_exception, "Division by zero should throw exception");
    
    // Test insufficient operands
    rpn = RPN();
    caught_exception = false;
    try {
        std::cout << "Testing insufficient operands (1 +)" << std::endl;
        rpn.evaluate("1 +");
    } catch (const RPN::InvalidExpressionError& e) {
        caught_exception = true;
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }
    TEST_ASSERT(caught_exception, "Insufficient operands should throw exception");
    
    // Test invalid token
    rpn = RPN();
    caught_exception = false;
    try {
        std::cout << "Testing invalid token (1 2 $)" << std::endl;
        rpn.evaluate("1 2 $");
    } catch (const RPN::InvalidExpressionError& e) {
        caught_exception = true;
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }
    TEST_ASSERT(caught_exception, "Invalid token should throw exception");
    
    // Test parentheses
    rpn = RPN();
    caught_exception = false;
    try {
        std::cout << "Testing parentheses ((1 + 1))" << std::endl;
        rpn.evaluate("(1 + 1)");
    } catch (const RPN::InvalidExpressionError& e) {
        caught_exception = true;
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }
    TEST_ASSERT(caught_exception, "Parentheses should throw exception");
    
    return true;
}

bool test_edge_cases() {
    std::cout << "\n=== Testing Edge Cases ===" << std::endl;
    RPN rpn;
    
    // Test single number
    TEST_ASSERT(rpn.evaluate("5") == 5, "Single number (5)");
    
    rpn = RPN();
    // Test multiple spaces
    TEST_ASSERT(rpn.evaluate("3   4    +") == 7, "Multiple spaces (3   4    +)");
    
    rpn = RPN();
    // Test maximum allowed digit
    TEST_ASSERT(rpn.evaluate("9 9 +") == 18, "Maximum digit addition (9 9 +)");
    
    return true;
}

int main() {
    int tests_passed = 0;
    int total_tests = 4;
    
    std::cout << "\nRunning RPN tests...\n" << std::endl;
    
    if (test_basic_operations()) {
        std::cout << " Basic operations tests passed" << std::endl;
        tests_passed++;
    }
    
    if (test_complex_expressions()) {
        std::cout << " Complex expressions tests passed" << std::endl;
        tests_passed++;
    }
    
    if (test_error_cases()) {
        std::cout << " Error cases tests passed" << std::endl;
        tests_passed++;
    }
    
    if (test_edge_cases()) {
        std::cout << " Edge cases tests passed" << std::endl;
        tests_passed++;
    }
    
    std::cout << "\nTest summary: " << tests_passed << "/" << total_tests 
              << " test suites passed" << std::endl;
    
    return tests_passed != total_tests;
}
