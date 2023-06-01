/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:40:47 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/01 18:50:04 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap() {
    std::cout << "ScavTrap Default Constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_name = name;
    std::cout << "ScavTrap " << this->_name << " created" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& src) {
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
    *this = src;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->_name << " destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs) {
    if (this != &rhs) {
        this->setName(rhs._name);
        this->setHitPoints(rhs._hitPoints);
        this->setEnergyPoints(rhs._energyPoints);
        this->setAttackDamage(rhs._attackDamage);
    }
    return *this;
}

void ScavTrap::attack(std::string const& target) {
    if (!this->healthCheck()) {
        std::cout << RED << "ScavTrap " << this->_name << " is dead"
            << RESET << std::endl;
        return;
    } else {
        std::cout << YELLOW << "ScavTrap " << this->_name << " attacks "
            << target << " causing " << this->_attackDamage
            << " points of damage!" << RESET << std::endl;
    }
    this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ScavTrap::guardGate() {
    if (!this->healthCheck()) {
        std::cout << RED << "ScavTrap " << this->_name << " is dead"
            << RESET << std::endl;
        return;
    }
    std::cout << PURPLE << "ScavTrap " << this->_name
        << " has enterred in Gate keeper mode"
        << RESET << std::endl;
}
