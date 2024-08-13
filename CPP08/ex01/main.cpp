#include "Span.hpp"

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    // Test avec une plage d'itérateurs
    std::vector<int> moreNumbers;
    for (int i = 20; i <= 25; ++i) {
        moreNumbers.push_back(i);
    }

    try {
        Span sp2 = Span(10);
        sp2.addNumber(moreNumbers.begin(), moreNumbers.end());
        std::cout << "Shortest span in sp2: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span in sp2: " << sp2.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
