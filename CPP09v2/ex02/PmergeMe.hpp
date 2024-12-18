#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <climits>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int> _deq;
    
    // Vector operations
    void fordJohnsonSortVector(std::vector<int>& arr);
    void insertElementVector(std::vector<int>& mainChain, int element, size_t position);
    std::vector<size_t> generateJacobsthalNumbers(size_t n);
    
    // Deque operations
    void fordJohnsonSortDeque(std::deque<int>& arr);
    void insertElementDeque(std::deque<int>& mainChain, int element, size_t position);

    // Helper functions
    bool isNumber(const std::string& s) const;
    void displayContainer(const std::string& prefix, const std::vector<int>& container) const;
    void validateNumbers(char** argv);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& other);

    void processInput(int argc, char** argv);
    void sort();

    class Error : public std::exception {
        private:
            std::string _msg;
        public:
            Error(const std::string& msg) : _msg(msg) {}
            virtual ~Error() throw() {}
            virtual const char* what() const throw() { return _msg.c_str(); }
    };
};

#endif
