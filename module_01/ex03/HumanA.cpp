/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:34:45 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/01 23:01:59 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/**
 * @brief Construct a new HumanA:: HumanA object.
 *
 * @param name The name of the human.
 * @param weapon The weapon of the human. HumanA will must have a reference to
 * a weapon in its constructor.
 */
HumanA::HumanA(std::string name, Weapon& weapon): _name(name), _weapon(weapon) {
    return;
}

/**
 * @brief Destroy the HumanA:: HumanA object.
 *
 */
HumanA::~HumanA(void) {
    return;
}

/**
 * @brief Attack with the weapon.
 *
 */
void HumanA::attack(void) {
    std::cout << this->_name << " attacks with his " << this->_weapon.getType()
        << std::endl;
}
