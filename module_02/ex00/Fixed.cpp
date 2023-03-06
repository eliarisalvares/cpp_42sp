/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:55:04 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/05 15:35:28 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}

Fixed::Fixed(const Fixed& src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

/**
 * @brief Assignment operator. Assigns the value of the right operand to the
 * left operand. The left operand must be a modifiable lvalue.
 *
 * @param fixed const&: the right operand
 * @return Fixed& *this: the left operand
 */
Fixed& Fixed::operator=(Fixed const& fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed) {
        this->_value = fixed.getRawBits();
    }
    return *this;
}

/**
 * @brief Get the Raw Bits object from the private attribute _value of the
 * instance of the class Fixed.
 *
 * @return int const: the raw bits
 */
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

/**
 * @brief Set the Raw Bits object from the private attribute _value of the
 * instance of the class Fixed. Raw bits are the bits that are not interpreted
 * by the computer.
 *
 * @param raw int const: the raw bits
 */
void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

