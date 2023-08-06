/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:18:36 by elraira-          #+#    #+#             */
/*   Updated: 2023/08/05 22:19:02 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_09_EX02_PMERGEME_HPP_
#define MODULE_09_EX02_PMERGEME_HPP_

#include <iostream>    // std::cout, std::endl
#include <iostream>   // std::cout, std::endl
#include <deque>     // std::deque
#include <vector>   // std::vector
#include <climits> // INT_MAX
#include <ctime>  // clock_t, clock, CLOCKS_PER_SEC
#include <cstdlib> // srand, rand

/**
 * @brief A class that performs parallel merge and insertion sort operations on containers.
 */
class PmergeMe {
public:
    /**
     * @brief Default constructor for PmergeMe.
     */
    PmergeMe();

    /**
     * @brief Copy constructor for PmergeMe.
     * @param rhs The PmergeMe instance to copy from.
     */
    PmergeMe(const PmergeMe& rhs);

    /**
     * @brief Assignment operator for PmergeMe.
     * @param rhs The PmergeMe instance to assign from.
     * @return Reference to the assigned PmergeMe instance.
     */
    PmergeMe& operator=(const PmergeMe& rhs);

    /**
     * @brief Destructor for PmergeMe.
     */
    ~PmergeMe();

    /**
     * @brief Fill the container with data based on the provided argument.
     * @param arg The argument to determine data filling.
     */
    void fillContainer(char* arg);

    /**
     * @brief Check if the argument is valid.
     * @param arg The argument to validate.
     * @return true if the argument is valid, false otherwise.
     */
    bool isValidArg(char* arg);

    /**
     * @brief Print the output based on the provided argument.
     * @param arg The argument to determine output printing.
     */
    void printOutput(char** arg);

    /**
     * @brief Sort the elements within a specified range using merge and insertion sort.
     * @tparam T The type of the container.
     * @param container The container to be sorted.
     * @param begin The starting index of the range to be sorted.
     * @param end The ending index of the range to be sorted.
     */
    template <class T>
    void sort(T& container, int begin, int end) {
        if (begin < end) {
            int mid = (begin + end) / 2;
            sort(container, begin, mid);
            sort(container, mid + 1, end);
            mergeInsertionSort(container, begin, mid, end);
        }
    }

    std::vector<unsigned long int> vec;
    std::deque<unsigned long int> deq;
    clock_t sttVec;
    clock_t endVec;
    clock_t sttDeq;
    clock_t endDeq;

    /**
     * @brief Perform merge and insertion sort on a specific range of the container.
     * @tparam T The type of the container.
     * @param container The container to be sorted.
     * @param left The starting index of the left subarray.
     * @param mid The ending index of the left subarray and the starting index of the right subarray.
     * @param right The ending index of the right subarray.
     */
    template <class T>
    void mergeInsertionSort(T& container, int left, int mid, int right) {
        std::vector<int> temp(right - left + 1);
        int i = left;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= right) {
            if (container[i] < container[j]) {
                temp[k] = container[i];
                ++i;
            } else {
                temp[k] = container[j];
                ++j;
            }
            ++k;
        }

        while (i <= mid) {
            temp[k] = container[i];
            ++i;
            ++k;
        }

        while (j <= right) {
            temp[k] = container[j];
            ++j;
            ++k;
        }

        for (int y = 0; y < k; ++y) {
            container[left + y] = temp[y];
        }
    }
};

#endif  // MODULE_09_EX02_PMERGEME_HPP_
