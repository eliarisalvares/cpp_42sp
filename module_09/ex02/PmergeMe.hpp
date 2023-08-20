/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 23:39:54 by elraira-          #+#    #+#             */
/*   Updated: 2023/08/20 14:41:59 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_09_EX02_PMERGEME_HPP_
#define MODULE_09_EX02_PMERGEME_HPP_

/* INCLUDES */
#include <algorithm> // std::sort
#include <deque> // std::deque
#include <iterator> // std::ostream_iterator
#include <sys/types.h> // uint
#include <utility> // std::pair
#include <vector> // std::vector
#include <iomanip> // std::setw
#include <iostream> // std::cout, std::endl
#include <sstream> // std::stringstream
#include <string> // std::string

/* COLORS */
#define RESET "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"

class PmergeMe {
 public:
    /* MAIN METHODS */
    static void sortVector(std::vector<uint> &arr);
    static void sortDeque(std::deque<uint> &arr);

    /* TEMPLATE */
    /**
     * @brief Checks if a sequence is sorted in ascending order.
     * @tparam T The type of the sequence.
     * @param sequence The sequence to check.
     * @return true if the sequence is sorted, false otherwise.
     */
    template <typename T>
    static bool isSorted(const T &sequence) {
        for (typename T::const_iterator current = sequence.begin();
            current != sequence.end(); ++current) {
            typename T::const_iterator next = current + 1;
            if (next == sequence.end()) {
                break;
            }
            if (*next < *current) {
                return false;
            }
        }
        return true;
    }

 private:
    /* CANONICAL */
    PmergeMe(void);
    PmergeMe(const PmergeMe &other);
    ~PmergeMe(void);
    PmergeMe &operator=(const PmergeMe &other);

    /* VECTOR */
    static std::vector<std::pair<uint, uint> > makePairs(std::vector<uint> &a);
    static std::vector<uint>
    extractLargestElement(std::vector<std::pair<uint, uint> > &pairs);
    static std::vector<uint>
    extractSmallerElement(std::vector<std::pair<uint, uint> > &pairs);

    /* DEQUE */
    static std::deque<std::pair<uint, uint> > makePairs(std::deque<uint> &a);
    static std::deque<uint>
    extractLargestElement(std::deque<std::pair<uint, uint> > &pairs);
    static std::deque<uint>
    extractSmallerElement(std::deque<std::pair<uint, uint> > &pairs);

    /* UTILS */
    static int getJacobsthalTerm(int n);
    // static void printVector(std::vector<std::pair<uint, uint> > &arr);

    /* TEMPLATE */
    /**
     * @brief Sorts pairs in a given container.
     * @param arr The container of pairs to be sorted.
     */
    template <typename T>
    static void sortPairs(T &arr) {
        typename T::iterator it;

        for (it = arr.begin(); it != arr.end(); it++) {
            if (it->first > it->second) {
                std::swap(it->first, it->second);
            }
        }
    }

    /**
     * @brief Sorts a given container by the largest value using insertion sort.
     * @tparam T The type of the container.
     * @param container The container to be sorted.
     * @param size The size of the container.
     */
    template <typename T>
    static void insertionSort(T &container, size_t size) {
        if (size <= 1) {
            return;
        }

        int index = size - 2;
        std::pair<uint, uint> lastElement = container[size - 1];

        insertionSort(container, size - 1);

        while (index >= 0 && container[index].second > lastElement.second) {
            container[index + 1] = container[index];
            index--;
        }
        container[index + 1] = lastElement;
    }

    /**
     * @brief Reinserts the last element into a given container.
     * @tparam T The type of the container.
     * @param container The input container.
     * @param lastElement A pointer to the last element to be reinserted.
     */
    template <typename T>
    static void reinsertLastElement(T &container, uint *lastElement) {
        typename T::iterator position;

        if (lastElement != nullptr) {
            position = getTargetPosition(container.begin(), container.end(),
                *lastElement);
            container.insert(position, *lastElement);
        }
    }

/**
 * @brief Creates a Jacobsthal chain from a given pending chain.
 * @tparam T The type of the container.
 * @param pendingChain The input pending chain.
 * @return The Jacobsthal chain created from the input pending chain.
 */
template <typename T>
static T createJacobsthalChain(T &pendingChain) {
    int index;
    size_t size;
    size_t jacobsthalIndex;
    T jacobsthalChain;

    if (pendingChain.empty()) {
        return jacobsthalChain;
    }

    index = 3;
    size = pendingChain.size();

    while ((jacobsthalIndex = getJacobsthalTerm(index)) < size) {
        // std::cout << "Adding " << jacobsthalIndex << " to Jacobsthal chain." << std::endl;
        jacobsthalChain.push_back(jacobsthalIndex);
        index++;
    }
    jacobsthalChain.push_back(size);

    return jacobsthalChain;
}

/**
 * @brief Creates an index sequence from a given Jacobsthal chain and
 * pending chain.
 * @param jacobsthalChain The input Jacobsthal chain.
 * @param pendingChain The input pending chain.
 * @return The index chain created from the input Jacobsthal and pending
 * chains.
 */
template <typename T>
static T createIndexChain(T &jacobsthalChain, T &pendingChain) {
    T indexChain(1, 0);
    size_t index = 1;
    size_t lastIndex = 1;
    typename T::iterator it;

    if (pendingChain.empty()) {
        return indexChain;
    }

    /* std::cout << "Jacobsthal chain: ";
    for (typename T::iterator jt = jacobsthalChain.begin(); jt != jacobsthalChain.end(); jt++) {
        std::cout << *jt << " ";
    }
    std::cout << std::endl; */

    // Iterate through the Jacobsthal chain.
    for (it = jacobsthalChain.begin(); it != jacobsthalChain.end(); it++) {
        index = *it;
        size_t pos = index;

        // Loop to add index positions to the index chain.
        while (pos > lastIndex) {
            // std::cout << "Adding " << (pos - 1) << " to index chain." << std::endl;
            indexChain.push_back(pos - 1);
            pos--;
        }
        lastIndex = index;
    }

    return indexChain;
}

    /**
     * @brief Finds the position of a target value in a given range.
     * @param begin The beginning of the range to search in.
     * @param end The end of the range to search in.
     * @param target The target value to search for.
     * @return An iterator pointing to the position of the target value in
     * the range.
     */
    template <typename T>
    static T getTargetPosition(T begin, T end, uint target) {
        T low, high;

        low = begin;
        high = end;
        while (low < high) {
            T mid = low + (high - low) / 2;
            if (*mid < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    /**
     * @brief Fills the main chain with values from the index and pending
     * chains.
     * @param mainChain The main chain to be filled.
     * @param indexChain The index chain to use for filling the main chain.
     * @param pendingChain The pending chain to use for filling the main
     * chain.
     */
    template <typename T>
    static void fillMainChain(T &mainChain, T &indexChain, T &pendingChain) {
        uint target;
        uint count;
        typename T::iterator it;
        typename T::iterator targetPosition;

        count = 0;
        for (it = indexChain.begin(); it != indexChain.end(); it++) {
            target = pendingChain.at(*it);
            targetPosition = getTargetPosition(mainChain.begin(),
                                mainChain.begin() + *it + 1 + count, target);
            mainChain.insert(targetPosition, target);
            count++;
        }
    }
};

/**
 * @brief Converts a sequence to a string.
 */
template <typename T>
std::string convertToString(T &sequence) {
    std::stringstream ss;
    for (typename T::const_iterator it = sequence.begin();
        it != sequence.end(); ++it) {
        ss << *it;
        if (it + 1 != sequence.end()) {
            ss << " ";
        }
    }
    return ss.str();
}

/**
 * @brief Prints the output of the sorting algorithm including the time it
 * took to sort the sequence.
 */
template <typename T>
void printOutput(const std::string &container, T &sequence, void (*func)(T &)) {
    std::cout << BLUE << "Before: " << RESET
        << convertToString(sequence) << RESET << std::endl;
    clock_t begin = clock();
    func(sequence);
    clock_t end = clock();
    double duration = ((double)(end - begin) / CLOCKS_PER_SEC * 1000000.0);

    std::cout << BLUE << "After:  " << RESET
        << convertToString(sequence) << RESET << std::endl;
    std::cout << BLUE << "Time to sort an array of " << RESET
        << sequence.size() << BLUE << " elements using " << RESET
        << container << BLUE << ": " << RESET
        << duration << "us" << std::endl << std::endl;
}

#endif // MODULE_09_EX02_PMERGE_ME_HPP_
