/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:38:07 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/01 23:04:43 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/**
 * @brief Construct a new HumanB:: HumanB object. HumanB may not have a weapon
 * unlike HumanA. The weapon will be set later by the setWeapon method.
 *
 * @param name The name of the human.
 */
HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {
    return;
}

/**
 * @brief Destroy the HumanB:: HumanB object.
 *
 */
HumanB::~HumanB(void) {
    return;
}

/**
 * @brief Set the weapon of the human.
 *
 * @param weapon The weapon of the human.
 */
void HumanB::setWeapon(Weapon& weapon) {
    this->_weapon = &weapon;
}

/**
 * @brief Attack with the weapon.
 *
 */
void HumanB::attack(void) {
    if (this->_weapon == NULL) {
        std::cout << this->_name << " has no weapon" << std::endl;
        return;
    }
    std::cout << this->_name << " attacks with his " << this->_weapon->getType()
        << std::endl;
}

