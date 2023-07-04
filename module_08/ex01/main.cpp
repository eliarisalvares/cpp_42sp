/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliarisalvares <eliarisalvares@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:34:03 by eliarisalva       #+#    #+#             */
/*   Updated: 2023/06/29 15:16:20 by eliarisalva      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << BLUE << "Vector: " << RESET;
    for (std::vector<int>::const_iterator it = sp.getNumbers().begin(); it != sp.getNumbers().end(); ++it) {
        std::cout << *it << " ";
        }
        std::cout << std::endl << std::endl;

    std::cout << BLUE << "Shortest span: " << RESET << sp.shortestSpan() << std::endl;
    std::cout << BLUE << "Longest span: " << RESET << sp.longestSpan() << std::endl;

    std::cout << std::endl;
    std::cout << BLUE << "Trying to add a number to a full vector: " << RESET << std::endl;
    try {
        sp.addNumber(42);
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl;
    std::cout << BLUE << "Trying to find the shortest span on a vector with less than 2 elements: " << RESET << std::endl;
    try {
        Span sp2 = Span(1);
        sp2.addNumber(42);
        std::cout << sp2.shortestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl;
    std::cout << BLUE << "Trying to find the longest span on a vector with less than 2 elements: " << RESET << std::endl;
    try {
        Span sp2 = Span(1);
        sp2.addNumber(42);
        std::cout << sp2.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl;
    std::cout << BLUE << "Adding a lot of numbers to a vector at once: " << RESET << std::endl;
    Span sp2 = Span(10000);
    std::vector<int> v;
    for (int i = 0; i < 10000; i++) {
        v.push_back(i);
    }
    sp2.addNumber(v.begin(), v.end());
    std::cout << BLUE << "Shortest span: " << RESET << sp2.shortestSpan() << std::endl;
    std::cout << BLUE << "Longest span: " << RESET << sp2.longestSpan() << std::endl;

    return 0;
}