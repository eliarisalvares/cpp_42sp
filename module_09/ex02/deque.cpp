/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:53:56 by elraira-          #+#    #+#             */
/*   Updated: 2023/08/20 11:59:29 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/**
 * @brief Sorts a given deque.
 * @param arr The deque to be sorted.
 */
void PmergeMe::sortDeque(std::deque<uint> &array) {
    uint *lastElement = NULL;
    std::deque<std::pair<uint, uint> > pairs;
    std::deque<uint> main;
    std::deque<uint> pending;
    std::deque<uint> jacob;
    std::deque<uint> index;

    if (array.size() < 2 || isSorted(array)) {
        return; // no need to sort if size < 2 or already sorted
    }
    if (array.size() % 2 == 1) {
        lastElement = &array.back();
        array.pop_back(); // remove last element from vector if odd size
    }
    pairs = makePairs(array); // creates pairs from input sequence
    sortPairs(pairs); // sorts each pair
    insertionSort(pairs, pairs.size()); // sorts pairs by largest value of each
    main = extractLargestElement(pairs); // split pairs into two sequences
    pending = extractSmallerElement(pairs);
    jacob = createJacobsthalChain(pending);
    index = createIndexChain(jacob, pending);
    fillMainChain(main, index, pending);
    reinsertLastElement(main, lastElement);
    array.assign(main.begin(), main.end());
}

/**
 * @brief Create pairs from a given deque.
 * @param arr The input deque.
 * @return A deque of pairs created from the input deque.
 */
std::deque<std::pair<uint, uint> >
PmergeMe::makePairs(std::deque<uint> &array) {
    std::deque<std::pair<uint, uint> > pairs;
    for (std::deque<uint>::iterator it = array.begin();
        it != array.end(); it += 2) {
        pairs.push_back(std::make_pair(*it, *(it + 1)));
  }
    return pairs;
}

/**
 * @brief Create the main chain from a given deque of pairs.
 * @param pairs The input deque of pairs.
 * @return The main chain created from the input deque of pairs.
 */
std::deque<uint>
PmergeMe::extractLargestElement(std::deque<std::pair<uint, uint> > &pairs) {
    std::deque<uint> mainSeq;
    for (std::deque<std::pair<uint, uint> >::iterator it = pairs.begin();
        it != pairs.end(); ++it) {
         mainSeq.push_back(it->second);
    }
     return mainSeq;
}

/**
 * @brief Create the pending chain from a given deque of pairs.
 * @param pairs The input deque of pairs.
 * @return The pending chain created from the input deque of pairs.
 */
std::deque<uint>
PmergeMe::extractSmallerElement(std::deque<std::pair<uint, uint> > &pairs) {
    std::deque<uint> pendingSeq;
    for (std::deque<std::pair<uint, uint> >::iterator it = pairs.begin();
        it != pairs.end(); ++it) {
        pendingSeq.push_back(it->first);
    }
    return pendingSeq;
}
