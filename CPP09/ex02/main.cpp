// PmergeMe.hpp
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>

class PmergeMe {
public:
    // Sorts a sequence of integers using the merge-insert sort algorithm
    static void sortVector(std::vector<int>& sequence);
    static void sortList(std::list<int>& sequence);

    // Utility functions
    static void printSequence(const std::string& prefix, const std::vector<int>& sequence);
    static void printSequence(const std::string& prefix, const std::list<int>& sequence);
};

#endif // PMERGEME_HPP


// PmergeMe.cpp
#include "PmergeMe.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>

// Merge-insert sort for vector
void PmergeMe::sortVector(std::vector<int>& sequence) {
    if (sequence.size() <= 1) return;

    size_t mid = sequence.size() / 2;
    std::vector<int> left(sequence.begin(), sequence.begin() + mid);
    std::vector<int> right(sequence.begin() + mid, sequence.end());

    sortVector(left);
    sortVector(right);

    std::merge(left.begin(), left.end(), right.begin(), right.end(), sequence.begin());
}

// Merge-insert sort for list
void PmergeMe::sortList(std::list<int>& sequence) {
    if (sequence.size() <= 1) return;

    auto mid = std::next(sequence.begin(), sequence.size() / 2);
    std::list<int> left(sequence.begin(), mid);
    std::list<int> right(mid, sequence.end());

    sortList(left);
    sortList(right);

    sequence.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(sequence));
}

// Print a vector
void PmergeMe::printSequence(const std::string& prefix, const std::vector<int>& sequence) {
    std::cout << prefix;
    for (const int& num : sequence) {
        std::cout << " " << num;
    }
    std::cout << std::endl;
}

// Print a list
void PmergeMe::printSequence(const std::string& prefix, const std::list<int>& sequence) {
    std::cout << prefix;
    for (const int& num : sequence) {
        std::cout << " " << num;
    }
    std::cout << std::endl;
}


// main.cpp
#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <cstdlib>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <sequence of positive integers>" << std::endl;
        return 1;
    }

    // Parse input into vector and list
    std::vector<int> vec;
    std::list<int> lst;
    try {
        for (int i = 1; i < argc; ++i) {
            int num = std::stoi(argv[i]);
            if (num < 0) throw std::invalid_argument("Negative number");
            vec.push_back(num);
            lst.push_back(num);
        }
    } catch (...) {
        std::cerr << "Error: invalid input." << std::endl;
        return 1;
    }

    // Display the original sequence
    PmergeMe::printSequence("Before:", vec);

    // Sort and time vector
    auto startVec = std::chrono::high_resolution_clock::now();
    PmergeMe::sortVector(vec);
    auto endVec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> durationVec = endVec - startVec;

    // Sort and time list
    auto startList = std::chrono::high_resolution_clock::now();
    PmergeMe::sortList(lst);
    auto endList = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> durationList = endList - startList;

    // Display the sorted sequence
    PmergeMe::printSequence("After:", vec);

    // Display timing information
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << durationVec.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << lst.size() << " elements with std::list: " << durationList.count() << " us" << std::endl;

    return 0;
}


// Makefile
NAME = PmergeMe
SRC = main.cpp PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
