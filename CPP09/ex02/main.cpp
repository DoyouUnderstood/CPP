#include "PmergeMe.hpp"
#include <ctime>
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: Please provide a sequence of positive integers.\n";
        return 1;
    }

    PmergeMe pmerge;

    try {
        for (int i = 1; i < argc; ++i) {
            int value = PmergeMe::stringToInt(argv[i]);
            pmerge.vec.push_back(value);
            pmerge.deq.push_back(value);
        }

        std::cout << "Before sorting (vector): ";
        pmerge.displayVector();

        std::cout << "Before sorting (deque): ";
        pmerge.displayDeque();

        clock_t startVec = clock();
        pmerge.sortWithVector();
        clock_t endVec = clock();
        double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;

        clock_t startDeque = clock();
        pmerge.sortWithDeque();
        clock_t endDeque = clock();
        double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1e6;

        std::cout << "After sorting (vector): ";
        pmerge.displayVector();

        std::cout << "After sorting (deque): ";
        pmerge.displayDeque();

        std::cout << "Time to process with vector: " << timeVec << " µs\n";
        std::cout << "Time to process with deque: " << timeDeque << " µs\n";

    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
