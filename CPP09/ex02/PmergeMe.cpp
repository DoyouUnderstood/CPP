#include "PmergeMe.hpp"

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

template <typename Container>
void PmergeMe::binaryInsert(Container& container, typename Container::value_type value) {
    typename Container::iterator position = std::lower_bound(container.begin(), container.end(), value);
    container.insert(position, value);
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
        }
        mainChain = fordJohnsonSortVector(largerElements);

        for (size_t i = 0; i < pairs.size(); i++) {
            pendingElements.push_back(pairs[i].second);
        }
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
        }
        mainChain = fordJohnsonSortDeque(largerElements);

        for (size_t i = 0; i < pairs.size(); i++) {
            pendingElements.push_back(pairs[i].second);
        }
    }

    std::vector<unsigned int> insertionSequence = generateInsertionSequence(pendingElements.size());
    
    // Insérer le premier élément s'il existe
    if (!pendingElements.empty()) {
        binaryInsert(mainChain, pendingElements[0]);
    }

    // Insérer le reste selon la séquence de Jacobsthal
    for (size_t i = 0; i < insertionSequence.size(); i++) {
        if (insertionSequence[i] - 1 < pendingElements.size()) {
            binaryInsert(mainChain, pendingElements[insertionSequence[i] - 1]);
        }
    }

    // Insérer l'élément restant s'il existe
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
