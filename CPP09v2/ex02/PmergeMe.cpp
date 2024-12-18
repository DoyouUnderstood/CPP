#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

bool PmergeMe::isNumber(const std::string& s) const {
    if (s.empty() || (s[0] != '-' && !isdigit(s[0]))) return false;
    for (size_t i = 1; i < s.length(); ++i) {
        if (!isdigit(s[i])) return false;
    }
    return true;
}

void PmergeMe::validateNumbers(char** argv) {
    for (int i = 1; argv[i]; ++i) {
        if (!isNumber(argv[i]))
            throw Error("Error: invalid input - non-numeric value");
        
        long num = std::atol(argv[i]);
        if (num < 0)
            throw Error("Error: negative numbers are not allowed");
        if (num > INT_MAX)
            throw Error("Error: number too large");
    }
}

void PmergeMe::processInput(int argc, char** argv) {
    if (argc < 2)
        throw Error("Error: no input provided");

    validateNumbers(argv);

    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        _vec.push_back(num);
        _deq.push_back(num);
    }
}

void PmergeMe::displayContainer(const std::string& prefix, const std::vector<int>& container) const {
    std::cout << prefix;
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i];
        if (i < container.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

std::vector<size_t> PmergeMe::generateJacobsthalNumbers(size_t n) {
    std::vector<size_t> jacobsthal;
    if (n == 0) return jacobsthal;
    
    jacobsthal.push_back(0);
    if (n == 1) return jacobsthal;
    jacobsthal.push_back(1);
    
    size_t i = 2;
    while (jacobsthal.back() < n) {
        size_t next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        if (next > n) break;
        jacobsthal.push_back(next);
        i++;
    }
    return jacobsthal;
}

void PmergeMe::insertElementVector(std::vector<int>& mainChain, int element, size_t position) {
    std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.begin() + position, element);
    mainChain.insert(it, element);
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr) {
    if (arr.size() <= 1) return;

    std::vector<std::pair<int, int> > pairs;
    size_t odd_element = static_cast<size_t>(-1);
    
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        int a = arr[i];
        int b = arr[i + 1];
        if (a > b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    
    if (arr.size() % 2 == 1) {
        odd_element = arr.back();
    }

    std::vector<std::pair<int, int> > sorted_pairs;
    if (pairs.size() > 1) {
        std::vector<int> larger_elements;
        for (size_t i = 0; i < pairs.size(); ++i) {
            larger_elements.push_back(pairs[i].second);
        }
        fordJohnsonSortVector(larger_elements);
        
        for (size_t i = 0; i < pairs.size(); ++i) {
            for (size_t j = 0; j < pairs.size(); ++j) {
                if (pairs[j].second == larger_elements[i]) {
                    sorted_pairs.push_back(pairs[j]);
                    break;
                }
            }
        }
    } else {
        sorted_pairs = pairs;
    }

    arr.clear();
    for (size_t i = 0; i < sorted_pairs.size(); ++i) {
        arr.push_back(sorted_pairs[i].second);
    }

    std::vector<int> pending;
    for (size_t i = 0; i < sorted_pairs.size(); ++i) {
        pending.push_back(sorted_pairs[i].first);
    }
    if (odd_element != static_cast<size_t>(-1)) {
        pending.push_back(odd_element);
    }

    std::vector<size_t> jacobsthal = generateJacobsthalNumbers(pending.size());
    
    if (!pending.empty()) {
        insertElementVector(arr, pending[0], arr.size());
    }

    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        size_t start = jacobsthal[i - 1];
        size_t end = jacobsthal[i];
        
        for (size_t j = end; j > start; --j) {
            if (j - 1 < pending.size()) {
                insertElementVector(arr, pending[j - 1], arr.size());
            }
        }
    }

    for (size_t i = jacobsthal.back() + 1; i <= pending.size(); ++i) {
        insertElementVector(arr, pending[i - 1], arr.size());
    }
}

void PmergeMe::insertElementDeque(std::deque<int>& mainChain, int element, size_t position) {
    std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.begin() + position, element);
    mainChain.insert(it, element);
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) return;

    std::deque<std::pair<int, int> > pairs;
    size_t odd_element = static_cast<size_t>(-1);
    
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        int a = arr[i];
        int b = arr[i + 1];
        if (a > b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    
    if (arr.size() % 2 == 1) {
        odd_element = arr.back();
    }

    std::deque<std::pair<int, int> > sorted_pairs;
    if (pairs.size() > 1) {
        std::deque<int> larger_elements;
        for (size_t i = 0; i < pairs.size(); ++i) {
            larger_elements.push_back(pairs[i].second);
        }
        fordJohnsonSortDeque(larger_elements);
        
        for (size_t i = 0; i < pairs.size(); ++i) {
            for (size_t j = 0; j < pairs.size(); ++j) {
                if (pairs[j].second == larger_elements[i]) {
                    sorted_pairs.push_back(pairs[j]);
                    break;
                }
            }
        }
    } else {
        sorted_pairs = pairs;
    }

    arr.clear();
    for (size_t i = 0; i < sorted_pairs.size(); ++i) {
        arr.push_back(sorted_pairs[i].second);
    }

    std::deque<int> pending;
    for (size_t i = 0; i < sorted_pairs.size(); ++i) {
        pending.push_back(sorted_pairs[i].first);
    }
    if (odd_element != static_cast<size_t>(-1)) {
        pending.push_back(odd_element);
    }

    std::vector<size_t> jacobsthal = generateJacobsthalNumbers(pending.size());
    
    if (!pending.empty()) {
        insertElementDeque(arr, pending[0], arr.size());
    }

    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        size_t start = jacobsthal[i - 1];
        size_t end = jacobsthal[i];
        
        for (size_t j = end; j > start; --j) {
            if (j - 1 < pending.size()) {
                insertElementDeque(arr, pending[j - 1], arr.size());
            }
        }
    }

    for (size_t i = jacobsthal.back() + 1; i <= pending.size(); ++i) {
        insertElementDeque(arr, pending[i - 1], arr.size());
    }
}

void PmergeMe::sort() {
    if (_vec.empty())
        return;

    std::vector<int> originalVec = _vec;
    displayContainer("Before: ", originalVec);

    clock_t startVec = clock();
    fordJohnsonSortVector(_vec);
    clock_t endVec = clock();
    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

    clock_t startDeq = clock();
    fordJohnsonSortDeque(_deq);
    clock_t endDeq = clock();
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    displayContainer("After:  ", _vec);
    
    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << std::fixed 
              << std::setprecision(5) << timeVec << " us" << std::endl;
    
    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque : " << std::fixed 
              << std::setprecision(5) << timeDeq << " us" << std::endl;
}
