/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:00:42 by elraira-          #+#    #+#             */
/*   Updated: 2023/04/21 22:49:31 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int Zombie::zombieCount = 0;

/**
 * @brief Construct a new Zombie:: Zombie object.
 */
Zombie::Zombie(void) {
    Zombie::zombieCount++;
    std::cout << "Zombie " << Zombie::zombieCount - 1
        << " was born!" << std::endl;
    return;
}

/**
 * @brief Destroy the Zombie:: Zombie object.
 */
Zombie::~Zombie(void) {
    Zombie::zombieCount--;
    std::cout << "Clicker, zombie " << Zombie::zombieCount
        << " was killed!" << std::endl;
    return;
}

/**
 * @brief Mandatory method to announce the zombie's name.
 *
 */
void Zombie::announce(void) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}

/**
 * @brief Set the name of the zombie.
 *
 * @param name The name of the zombie.
 */
void Zombie::setName(std::string name) {
    this->_name = name;
    return;
}
