/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:44:09 by elraira-          #+#    #+#             */
/*   Updated: 2023/08/20 14:44:10 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/**
 * @brief Sorts a given vector.
 * @param arr The vector to be sorted.
 */
void PmergeMe::sortVector(std::vector<uint> &array) {
    uint *lastElement = NULL;
    std::vector<std::pair<uint, uint> > pairs;
    std::vector<uint> main;
    std::vector<uint> pending;
    std::vector<uint> jacob;
    std::vector<uint> index;

    if (array.size() < 2 || isSorted(array)) {
        return; // no need to sort if size < 2 or already sorted
    }
    if (array.size() % 2 == 1) {
        lastElement = &array.back();
        array.pop_back(); // remove last element from vector if odd size
    }
    pairs = makePairs(array); // creates pairs from input sequence
    // printVector(pairs);
    sortPairs(pairs); // sorts each pair
    // printVector(pairs);
    insertionSort(pairs, pairs.size()); // sorts pairs by largest value of each
    // printVector(pairs);
    main = extractLargestElement(pairs); // split pairs into two sequences
    pending = extractSmallerElement(pairs);
    jacob = createJacobsthalChain(pending);
    index = createIndexChain(jacob, pending);
    fillMainChain(main, index, pending);
    reinsertLastElement(main, lastElement);
    array.assign(main.begin(), main.end());
}

/**
 * @brief Prints a given vector.
 * @param arr The vector to be printed.
 */
/* void PmergeMe::printVector(std::vector<std::pair<uint, uint> > &array) {
    for (std::vector<std::pair<uint, uint> >::iterator it = array.begin();
        it != array.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;
} */


/**
 * @brief Create pairs from a given sequence.
 * @param arr The input sequence.
 * @return A vector of pairs created from the input sequence.
 */
std::vector<std::pair<uint, uint> >
PmergeMe::makePairs(std::vector<uint> &array) {
    std::vector<std::pair<uint, uint> > pairs;
    for (std::vector<uint>::iterator it = array.begin();
        it != array.end(); it += 2) {
        pairs.push_back(std::make_pair(*it, *(it + 1)));
    }
    return pairs;
}

/**
 * @brief Create the main sequence from a given sequence of pairs. The main
 * sequence is the sequence of the largest values of each pair.
 * @param pairs The input sequence of pairs.
 * @return The main sequence created from the input sequence of pairs.
 */
std::vector<uint>
PmergeMe::extractLargestElement(std::vector<std::pair<uint, uint> > &pairs) {
    std::vector<uint> mainSeq;
    for (std::vector<std::pair<uint, uint> >::iterator it = pairs.begin();
        it != pairs.end(); ++it) {
        mainSeq.push_back(it->second);
    }
    return mainSeq;
}

/**
 * @brief Create the pending sequence from a given sequence of pairs. The
 * pending sequence is the sequence of the smallest values of each pair.
 * @param pairs The input sequence of pairs.
 * @return The pending sequence created from the input sequence of pairs.
 */
std::vector<uint>
PmergeMe::extractSmallerElement(std::vector<std::pair<uint, uint> > &pairs) {
     std::vector<uint> pendingSeq;
    for (std::vector<std::pair<uint, uint> >::iterator it = pairs.begin();
        it != pairs.end(); ++it) {
        pendingSeq.push_back(it->first);
    }
    return pendingSeq;
}
