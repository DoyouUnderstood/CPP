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

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int> _deq;
    
    // Vector operations
    void mergeInsertSortVector(std::vector<int>& arr, size_t left, size_t right);
    void insertSortVector(std::vector<int>& arr, size_t left, size_t right);
    void mergeVector(std::vector<int>& arr, size_t left, size_t mid, size_t right);
    
    // Deque operations
    void mergeInsertSortDeque(std::deque<int>& arr, size_t left, size_t right);
    void insertSortDeque(std::deque<int>& arr, size_t left, size_t right);
    void mergeDeque(std::deque<int>& arr, size_t left, size_t mid, size_t right);

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
