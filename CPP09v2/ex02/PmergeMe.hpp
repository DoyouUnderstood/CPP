#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <algorithm>
#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <ctime>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int> _deq;

    // Input validation
    bool isNumber(const std::string& s) const;
    bool isValidNumber(const std::string& s) const;
    void validateNumbers(char** argv);

    // Display helpers
    void displayContainer(const std::string& prefix, const std::vector<int>& container) const;
    void displayTimings(double vec_time, double deq_time) const;

    // Utility functions
    std::vector<size_t> generateJacobsthalNumbers(size_t n);

    // Sorting helpers
    template<typename Container>
    void insertElement(Container& mainChain, int element, size_t position);

    template<typename Container>
    std::vector<std::pair<int, int> > createPairs(const Container& arr);

    template<typename Container>
    void mergePairs(Container& arr, const std::vector<std::pair<int, int> >& pairs, int odd_element);

    template<typename Container>
    void insertPendingElements(Container& arr, const std::vector<int>& pending);

    void fordJohnsonSortVector(std::vector<int>& arr);
    void fordJohnsonSortDeque(std::deque<int>& arr);

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
