#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <limits>

class Span 
{
    private:
        std::vector<int> numbers;
        unsigned int maxSize;

    public:
        Span(unsigned int N) : maxSize(N) {}

        void addNumber(int number) {
            if (numbers.size() >= maxSize) {
                throw std::out_of_range("Cannot add more numbers");
            }
            numbers.push_back(number);
        }

        template <typename InputIterator>
        void addNumber(InputIterator begin, InputIterator end) {
            if (std::distance(begin, end) + numbers.size() > maxSize) {
                throw std::out_of_range("Cannot add more numbers, Span will exceed max size");
            }
            numbers.insert(numbers.end(), begin, end);
        }

        int shortestSpan() const {
            if (numbers.size() < 2) {
                throw std::logic_error("Not enough numbers to find a span");
            }

            std::vector<int> sortedNumbers = numbers;
            std::sort(sortedNumbers.begin(), sortedNumbers.end());

            int minSpan = std::numeric_limits<int>::max();
            for (size_t i = 1; i < sortedNumbers.size(); ++i) {
                int span = sortedNumbers[i] - sortedNumbers[i - 1];
                if (span < minSpan) {
                    minSpan = span;
                }
            }
            return minSpan;
        }

        int longestSpan() const {
            if (numbers.size() < 2) {
                throw std::logic_error("Not enough numbers to find a span");
            }

            int minValue = *std::min_element(numbers.begin(), numbers.end());
            int maxValue = *std::max_element(numbers.begin(), numbers.end());
            return maxValue - minValue;
        }
};

#endif
