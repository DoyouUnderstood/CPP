#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <climits>

#define DEBUG 0
#define LOG(msg) \
    if (DEBUG) { \
        std::cout << msg << std::endl; \
    }



class PmergeMe {
public:
    std::vector<int> vec;
    std::deque<int> deq;

    void sortWithVector();
    void sortWithDeque();

    void displayVector() const;
    void displayDeque() const;

    static int stringToInt(const std::string& str);

private:
    void splitIntoPairsVector(const std::vector<int>& input, std::vector<std::pair<int, int> >& pairs, int& stray);
    void splitIntoPairsDeque(const std::deque<int>& input, std::deque<std::pair<int, int> >& pairs, int& stray);

    std::vector<int> fordJohnsonSortVector(std::vector<int>& input);
    std::deque<int> fordJohnsonSortDeque(std::deque<int>& input);

    template <typename Container>
    void binaryInsert(Container& container, typename Container::value_type value);

    unsigned int getNextJacobsthal(unsigned int n);
    std::vector<unsigned int> generateInsertionSequence(unsigned int size);
};

#endif
