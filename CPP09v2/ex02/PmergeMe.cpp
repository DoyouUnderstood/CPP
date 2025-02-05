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

// ========== Input Validation ==========
bool PmergeMe::isNumber(const std::string& s) const {
    if (s.empty() || (!isdigit(s[0]) && s[0] != '-')) 
        return false;
    
    for (std::string::const_iterator it = s.begin() + 1; it != s.end(); ++it) {
        if (!isdigit(*it)) return false;
    }
    return true;
}

bool PmergeMe::isValidNumber(const std::string& s) const {
    if (!isNumber(s))
        return false;
        
    long num = std::atol(s.c_str());
    return (num >= 0 && num <= INT_MAX);
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

// ========== Display Functions ==========
void PmergeMe::displayContainer(const std::string& prefix, const std::vector<int>& container) const {
    std::cout << prefix;
    for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it;
        if (it + 1 != container.end())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::displayTimings(double vec_time, double deq_time) const {
    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << vec_time << " us\n";
    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque  : " << deq_time << " us\n";
}

// ========== Utility Functions ==========
std::vector<size_t> PmergeMe::generateJacobsthalNumbers(size_t n) {
    std::vector<size_t> jacobsthal;
    if (n == 0) return jacobsthal;
    
    jacobsthal.push_back(0);
    if (n == 1) return jacobsthal;
    
    jacobsthal.push_back(1);
    while (jacobsthal.back() < n) {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next > n) break;
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

// ========== Vector Sorting Implementation ==========
template<typename Container>
void PmergeMe::insertElement(Container& mainChain, int element, size_t position) {
    typename Container::iterator it = std::lower_bound(mainChain.begin(), 
                                                     mainChain.begin() + position, 
                                                     element);
    mainChain.insert(it, element);
}


template<typename Container>
std::vector<std::pair<int, int> > PmergeMe::createPairs(const Container& arr) {
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        int a = arr[i], b = arr[i + 1];
        if (a > b) std::swap(a, b); // Tri de la paire
        pairs.push_back(std::make_pair(a, b));
    }
    return pairs;
}


template<typename Container>
void PmergeMe::mergePairs(Container& arr, 
                         const std::vector<std::pair<int, int> >& pairs, 
                         int odd_element) {
    arr.clear();
    std::vector<int> pending;

    // Add larger elements to main chain
    for (size_t i = 0; i < pairs.size(); ++i) {
        arr.push_back(pairs[i].second);
    }

    // Collect smaller elements and odd element
    for (size_t i = 0; i < pairs.size(); ++i) {
        pending.push_back(pairs[i].first);
    }
    if (odd_element != -1 && std::find(arr.begin(), arr.end(), odd_element) == arr.end()) {
        pending.push_back(odd_element);
    }

    // Insert elements using Jacobsthal sequence
    insertPendingElements(arr, pending);
}

template<typename Container>
void PmergeMe::insertPendingElements(Container& arr, const std::vector<int>& pending) {
    if (pending.empty()) return;

    std::cout << "Inserting first element: " << pending[0] << std::endl;
    insertElement(arr, pending[0], arr.size());

    std::vector<size_t> jacobsthal = generateJacobsthalNumbers(pending.size());
    std::cout << "Jacobsthal sequence: ";
    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        std::cout << jacobsthal[i] << " ";
    }
    std::cout << std::endl;

    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        for (size_t j = jacobsthal[i]; j > jacobsthal[i - 1]; --j) {
            if (j - 1 < pending.size()) {
                std::cout << "Inserting element: " << pending[j - 1] << std::endl;
                insertElement(arr, pending[j - 1], arr.size());
            }
        }
    }

    for (size_t i = jacobsthal.back() + 1; i <= pending.size(); ++i) {
        std::cout << "Inserting remaining element: " << pending[i - 1] << std::endl;
        insertElement(arr, pending[i - 1], arr.size());
    }
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr) {
    if (arr.size() <= 1) return;

    // Handle odd element
    int odd_element = (arr.size() % 2 == 1) ? arr.back() : -1;
    
    // Create and sort pairs
    std::vector<std::pair<int, int> > pairs = createPairs(arr);
    if (pairs.size() > 1) {
        std::vector<int> larger_elements;
        for (size_t i = 0; i < pairs.size(); ++i) {
            larger_elements.push_back(pairs[i].second);
        }
        fordJohnsonSortVector(larger_elements);
        
        // Reconstruct pairs based on sorted larger elements
        std::vector<std::pair<int, int> > sorted_pairs;
        for (size_t i = 0; i < larger_elements.size(); ++i) {
            for (size_t j = 0; j < pairs.size(); ++j) {
                if (pairs[j].second == larger_elements[i]) {
                    sorted_pairs.push_back(pairs[j]);
                    break;
                }
            }
        }
        pairs = sorted_pairs;
    }

    // Merge pairs using insertion
    mergePairs(arr, pairs, odd_element);
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) return;

    // Handle odd element
    int odd_element = (arr.size() % 2 == 1) ? arr.back() : -1;
    
    // Create and sort pairs
    std::vector<std::pair<int, int> > pairs = createPairs(arr);
    if (pairs.size() > 1) {
        std::deque<int> larger_elements;
        for (size_t i = 0; i < pairs.size(); ++i) {
            larger_elements.push_back(pairs[i].second);
        }
        fordJohnsonSortDeque(larger_elements);
        
        // Reconstruct pairs based on sorted larger elements
        std::vector<std::pair<int, int> > sorted_pairs;
        for (size_t i = 0; i < larger_elements.size(); ++i) {
            for (size_t j = 0; j < pairs.size(); ++j) {
                if (pairs[j].second == larger_elements[i]) {
                    sorted_pairs.push_back(pairs[j]);
                    break;
                }
            }
        }
        pairs = sorted_pairs;
    }

    // Merge pairs using insertion
    mergePairs(arr, pairs, odd_element);
}

void PmergeMe::sort() {
    if (_vec.empty() || _deq.empty()) return;

    std::vector<int> vec_before = _vec;
    std::deque<int> deq_before = _deq;

    // Sort both containers and measure time
    clock_t start_vec = clock();
    fordJohnsonSortVector(_vec);
    clock_t end_vec = clock();

    clock_t start_deq = clock();
    fordJohnsonSortDeque(_deq);
    clock_t end_deq = clock();

    // Display results
    displayContainer("Before: ", vec_before);
    displayContainer("After:  ", _vec);
    
    double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;
    double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000;
    
    displayTimings(time_vec, time_deq);
}
