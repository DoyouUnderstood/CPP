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

// Vector Implementation
void PmergeMe::insertSortVector(std::vector<int>& arr, size_t left, size_t right) {
    for (size_t i = left + 1; i <= right; i++) {
        int key = arr[i];
        size_t j = i;
        while (j > left && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

void PmergeMe::mergeVector(std::vector<int>& arr, size_t left, size_t mid, size_t right) {
    std::vector<int> temp(right - left + 1);
    size_t i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (i = 0; i < k; i++)
        arr[left + i] = temp[i];
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr, size_t left, size_t right) {
    if (right - left <= 10) {
        insertSortVector(arr, left, right);
        return;
    }

    size_t mid = left + (right - left) / 2;
    mergeInsertSortVector(arr, left, mid);
    mergeInsertSortVector(arr, mid + 1, right);
    mergeVector(arr, left, mid, right);
}

// Deque Implementation
void PmergeMe::insertSortDeque(std::deque<int>& arr, size_t left, size_t right) {
    for (size_t i = left + 1; i <= right; i++) {
        int key = arr[i];
        size_t j = i;
        while (j > left && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

void PmergeMe::mergeDeque(std::deque<int>& arr, size_t left, size_t mid, size_t right) {
    std::deque<int> temp(right - left + 1);
    size_t i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (i = 0; i < k; i++)
        arr[left + i] = temp[i];
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr, size_t left, size_t right) {
    if (right - left <= 10) {
        insertSortDeque(arr, left, right);
        return;
    }

    size_t mid = left + (right - left) / 2;
    mergeInsertSortDeque(arr, left, mid);
    mergeInsertSortDeque(arr, mid + 1, right);
    mergeDeque(arr, left, mid, right);
}

void PmergeMe::sort() {
    if (_vec.empty())
        return;

    std::vector<int> originalVec = _vec;
    displayContainer("Before: ", originalVec);

    // Sort with vector
    clock_t startVec = clock();
    mergeInsertSortVector(_vec, 0, _vec.size() - 1);
    clock_t endVec = clock();
    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

    // Sort with deque
    clock_t startDeq = clock();
    mergeInsertSortDeque(_deq, 0, _deq.size() - 1);
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
