#include "PmergeMe.hpp"

template <typename T>
std::string to_string(T value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

int PmergeMe::stringToInt(const std::string& str) {
    std::stringstream ss(str);
    int value;
    ss >> value;

    if (ss.fail() || !ss.eof() || value < 0 || value > INT_MAX) {
        throw std::runtime_error("Invalid number: " + str);
    }
    return value;
}

// Génère le prochain nombre de Jacobsthal
unsigned int PmergeMe::getNextJacobsthal(unsigned int n) {
    if (n == 0) 
        return 0;
    if (n == 1) 
        return 1;
    return getNextJacobsthal(n - 1) + 2 * getNextJacobsthal(n - 2);
}

// Génère la séquence d'insertion
std::vector<unsigned int> PmergeMe::generateInsertionSequence(unsigned int size) {
    std::vector<unsigned int> sequence;
    if (size <= 1) return sequence;

    std::vector<unsigned int> jacobsthal;
    unsigned int i = 0;
    unsigned int next;
    while ((next = getNextJacobsthal(i)) <= size) {
        jacobsthal.push_back(next);
        i++;
    }

    for (size_t i = 1; i < jacobsthal.size(); i++) {
        for (unsigned int j = jacobsthal[i]; j > jacobsthal[i-1]; j--) {
            if (j <= size) {
                sequence.push_back(j);
            }
        }
    }

    return sequence;
}

// void PmergeMe::splitIntoPairsVector(const std::vector<int>& input, std::vector<std::pair<int, int> >& pairs, int& stray) {
//     stray = -1;
//     for (size_t i = 0; i + 1 < input.size(); i += 2) {
//         if (input[i] > input[i + 1]) {
//             pairs.push_back(std::make_pair(input[i], input[i + 1]));
//         } else {
//             pairs.push_back(std::make_pair(input[i + 1], input[i]));
//         }
//     }
//     if (input.size() % 2 != 0) {
//         stray = input.back();
//     }
// }

// void PmergeMe::splitIntoPairsDeque(const std::deque<int>& input, std::deque<std::pair<int, int> >& pairs, int& stray) {
//     stray = -1;
//     for (size_t i = 0; i + 1 < input.size(); i += 2) {
//         if (input[i] > input[i + 1]) {
//             pairs.push_back(std::make_pair(input[i], input[i + 1]));
//         } else {
//             pairs.push_back(std::make_pair(input[i + 1], input[i]));
//         }
//     }
//     if (input.size() % 2 != 0) {
//         stray = input.back();
//     }
// }

template <typename Container>
void PmergeMe::binaryInsert(Container& container, typename Container::value_type value) {
    typename Container::iterator position = std::lower_bound(container.begin(), container.end(), value);
    if (position == container.end() || *position != value) { // Évite les doublons
        LOG("Inserting " + to_string(value) + " at position " + to_string(std::distance(container.begin(), position)));
        container.insert(position, value);
    } else {
        LOG("Skipping duplicate value: " + to_string(value));
    }
}


void PmergeMe::splitIntoPairsVector(const std::vector<int>& input, std::vector<std::pair<int, int> >& pairs, int& stray) {
    stray = -1;
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        if (input[i] > input[i + 1]) {
            pairs.push_back(std::make_pair(input[i], input[i + 1]));
        } else {
            pairs.push_back(std::make_pair(input[i + 1], input[i]));
        }
    }
    if (input.size() % 2 != 0) {
        stray = input.back();
    }

    LOG("Pairs created:");
    if (DEBUG)
    {
        for (size_t i = 0; i < pairs.size(); i++) {
            std::cout << "(" << pairs[i].first << "," << pairs[i].second << ") ";
        }   
        std::cout << std::endl;
        if (stray != -1) {
            LOG("Stray element: " + to_string(stray));
        }
    }
}


void PmergeMe::splitIntoPairsDeque(const std::deque<int>& input, std::deque<std::pair<int, int> >& pairs, int& stray) {
    stray = -1;
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        if (input[i] > input[i + 1]) {
            pairs.push_back(std::make_pair(input[i], input[i + 1]));
        } else {
            pairs.push_back(std::make_pair(input[i + 1], input[i]));
        }
    }
    if (input.size() % 2 != 0) {
        stray = input.back();
    }
}

std::vector<int> PmergeMe::fordJohnsonSortVector(std::vector<int>& input) {
    if (input.size() <= 1) 
        return input;

    std::vector<std::pair<int, int> > pairs;
    int stray;
    splitIntoPairsVector(input, pairs, stray);

    std::vector<int> mainChain;
    std::vector<int> pendingElements;
    
    if (!pairs.empty()) {
        std::vector<int> largerElements;
        for (size_t i = 0; i < pairs.size(); i++) {
            largerElements.push_back(pairs[i].first);
            pendingElements.push_back(pairs[i].second);
        }
        mainChain = fordJohnsonSortVector(largerElements);
    }

    LOG("Main chain after sorting larger elements:");
    if (DEBUG)
    {
        for (size_t i = 0; i < mainChain.size(); i++) {
            std::cout << mainChain[i] << " ";
        }
        std::cout << std::endl;

        LOG("Pending elements:");
        for (size_t i = 0; i < pendingElements.size(); i++) {
            std::cout << pendingElements[i] << " ";
        }
        std::cout << std::endl;
    }

    std::vector<unsigned int> insertionSequence = generateInsertionSequence(pendingElements.size());

    if (!pendingElements.empty()) {
        LOG("Inserting first pending element: " + to_string(pendingElements[0]));
        binaryInsert(mainChain, pendingElements[0]);
    }

    for (size_t i = 0; i < insertionSequence.size(); i++) {
        if (insertionSequence[i] - 1 < pendingElements.size()) {
            LOG("Binary inserting element " + to_string(pendingElements[insertionSequence[i] - 1]));
            binaryInsert(mainChain, pendingElements[insertionSequence[i] - 1]);
        }
    }

    if (stray != -1) {
        LOG("Binary inserting stray element: " + to_string(stray));
        binaryInsert(mainChain, stray);
    }

    LOG("Final sorted main chain:");
    if (DEBUG)
    {
        for (size_t i = 0; i < mainChain.size(); i++) {
            std::cout << mainChain[i] << " ";
        }
        std::cout << std::endl;
    }

    return mainChain;
}


std::deque<int> PmergeMe::fordJohnsonSortDeque(std::deque<int>& input) {
    if (input.size() <= 1) return input;

    std::deque<std::pair<int, int> > pairs;
    int stray;
    splitIntoPairsDeque(input, pairs, stray);

    std::deque<int> mainChain;
    std::deque<int> pendingElements;
    
    if (!pairs.empty()) {
        std::deque<int> largerElements;
        for (size_t i = 0; i < pairs.size(); i++) {
            largerElements.push_back(pairs[i].first);
            pendingElements.push_back(pairs[i].second);
        }
        mainChain = fordJohnsonSortDeque(largerElements);
    }

    std::vector<unsigned int> insertionSequence = generateInsertionSequence(pendingElements.size());
    
    if (!pendingElements.empty()) {
        binaryInsert(mainChain, pendingElements[0]);
    }

    for (size_t i = 0; i < insertionSequence.size(); i++) {
        if (insertionSequence[i] - 1 < pendingElements.size()) {
            binaryInsert(mainChain, pendingElements[insertionSequence[i] - 1]);
        }
    }

    if (stray != -1) {
        binaryInsert(mainChain, stray);
    }

    return mainChain;
}

void PmergeMe::sortWithVector() {
    vec = fordJohnsonSortVector(vec);
}

void PmergeMe::sortWithDeque() {
    deq = fordJohnsonSortDeque(deq);
}

void PmergeMe::displayVector() const {
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

void PmergeMe::displayDeque() const {
    for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}
