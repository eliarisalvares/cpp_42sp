/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:30:28 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/01 23:08:08 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/**
 * @brief Construct a new Weapon:: Weapon object.
 *
 * @param type The type of the weapon.
 */
Weapon::Weapon(std::string type): _type(type) {
    return;
}

/**
 * @brief Destroy the Weapon:: Weapon object.
 *
 */
Weapon::~Weapon(void) {
    return;
}

/**
 * @brief Get the type of the weapon.
 *
 * @return const std::string& The type of the weapon.
 */
const std::string& Weapon::getType(void) {
    return (this->_type);
}

/**
 * @brief Set the type of the weapon.
 *
 * @param type The type of the weapon.
 */
void Weapon::setType(std::string type) {
    this->_type = type;
}
