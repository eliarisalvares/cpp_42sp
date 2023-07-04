/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliarisalvares <eliarisalvares@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:21:45 by eliarisalva       #+#    #+#             */
/*   Updated: 2023/06/29 15:15:26 by eliarisalva      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/**
 * @brief Constructor for Span class.
 * 
 * @param N Maximum number of elements that can be stored in the container.
 */
Span::Span(unsigned int N) : _n(N) {
    std::cout << "Span object created with N = " << N << std::endl;
}

/**
 * @brief Copy constructor for Span class.
 * 
 * @param other Span object to be copied.
 */
Span::Span(const Span &src) {
    std::cout << "Span object of size " << src._n << " copied." << std::endl;
    *this = src;
}

/**
 * @brief Destructor for Span class.
 */
Span::~Span() {
    std::cout << "Span object of size " << this->_n << " destroyed." << std::endl;
}

/**
 * @brief Assignation operator overload for Span class.
 * 
 * @param other Span object to be copied.
 * @return Span& Reference to the Span object copied.
 */
Span &Span::operator=(const Span &other) {
    if (this != &other) {
        this->_n = other._n;
        this->_numbers = other._numbers;
    }
    return *this;
}

/**
 * @brief Member function that adds a single number to the container.
 * This is the function that will be used to add numbers to the container.
 * If the container is full, it will throw an exception.
 * 
 * @param number 
 */
void Span::addNumber(int number) {
    std::cout << "Adding one single " << number << " to the container." << std::endl;
    if (this->_numbers.size() >= this->_n) {
        throw Span::SpanException();
    }
    this->_numbers.push_back(number);
}

/**
 * @brief Member function that adds a range of numbers to the container.
 * This is the function that will be used to add numbers to the container.
 * If the container is full, it will throw an exception.
 * 
 * @param begin Iterator to the first element in the range.
 * @param end Iterator to the last element in the range.
 */
void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    std::cout << "Adding " << std::distance(begin, end) << " numbers to the container." << std::endl;
    if (this->_numbers.size() + std::distance(begin, end) > this->_n) {
        throw Span::SpanException();
    }
    this->_numbers.insert(this->_numbers.end(), begin, end);
}

/**
 * @brief This function will sort the vector and then search
 * for the first span (distance between two numbers) between
 * the numbers stored in the Span object. If there are no
 * numbers or only one number stored, it will throw an exception.
 * 
 * @return int shortest span
 */
int Span::shortestSpan() {
    if (this->_numbers.size() <= 1) {
        throw Span::SpanException();
    }

    std::vector<int> tmp = this->_numbers;
    std::sort(tmp.begin(), tmp.end());
    int shortest = tmp[1] - tmp[0];

    for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; ++it) {
        if (*(it + 1) - *it < shortest) {
        shortest = *(it + 1) - *it;
        }
    }

    return shortest;
}

/**
 * @brief This function will sort the vector and then search
 * for the longest span (distance between two numbers) between
 * the numbers stored in the Span object. If there are no
 * numbers or only one number stored, it will throw an exception.
 * 
 * @return int longest span
 */
int Span::longestSpan() {
    if (this->_numbers.size() <= 1) {
        throw Span::SpanException();
    }

    std::vector<int> tmp = this->_numbers;
    std::sort(tmp.begin(), tmp.end());

    return tmp[tmp.size() - 1] - tmp[0];
}

/**
 * @brief Getter for the _n attribute.
 * 
 * @return int _n
 */
int Span::getN() const {
    return this->_n;
}

/**
 * @brief Getter for the _numbers attribute.
 * 
 * @return const std::vector<int>& _numbers
 */
const std::vector<int> &Span::getNumbers() const {
    return this->_numbers;
}
