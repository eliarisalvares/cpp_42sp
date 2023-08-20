/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:09:48 by elraira-          #+#    #+#             */
/*   Updated: 2023/08/20 10:13:47 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {

    if (argc < 3) {
        std::cout << RED << "ERROR: Invalid number of arguments. "
            << "Please use at least 2 positive integers." << RESET << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (atoi(argv[i]) < 0) {
            std::cout << RED << "ERROR: Invalid argument type. "
                << "Please use only positive integers." << RESET << std::endl;
            return 1;
        }
    }

    uint *arr = new uint[argc - 1];

    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }

    std::vector<uint> vec(arr, arr + argc - 1);
    std::deque<uint> deq(arr, arr + argc - 1);
    printOutput("std::vector", vec, PmergeMe::sortVector);
    printOutput("std::deque", deq, PmergeMe::sortDeque);

    delete[] arr;

    return (0);
}
