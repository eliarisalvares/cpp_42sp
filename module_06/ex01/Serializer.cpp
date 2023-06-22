/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 00:57:20 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/21 20:36:16 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* Canonical Functions */
/**
 * @brief Default constructor.
 */
Serializer::Serializer() {
    std::cout << "Default Constructor Called" << std::endl;
}

/**
 * @brief Copy constructor.
 *
 * @param src Serializer object to be copied.
 */
Serializer::Serializer(Serializer const &src) {
    std::cout << "Copy Constructor Called" << std::endl;
    *this = src;
}

/**
 * @brief Destructor.
 */
Serializer::~Serializer() {
    std::cout << "Destructor Called" << std::endl;
}

/**
 * @brief Assignation operator overload.
 *
 * @param rhs Serializer object to be copied.
 * @return Serializer& reference to the copied object.
 */
Serializer &Serializer::operator=(Serializer const &rhs) {
    std::cout << "Assignation Operator Called" << std::endl;
    (void) rhs;
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

