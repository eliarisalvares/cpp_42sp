/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:40:47 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/01 11:22:02 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap() {
    std::cout << "ScavTrap Default Constructor called" << std::endl;
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    this->setName(name);
    std::cout << "ScavTrap Constructor called" << std::endl;
    std::cout << "ScavTrap " << this->getName() << " created" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& src) {
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
    *this = src;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called" << std::endl;
    std::cout << "ScavTrap " << this->getName() << " destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs) {
    if (this != &rhs) {
        this->setName(rhs.getName());
        this->setHitPoints(rhs.getHitPoints());
        this->setEnergyPoints(rhs.getEnergyPoints());
        this->setAttackDamage(rhs.getAttackDamage());
    }
    return *this;
}

void ScavTrap::attack(std::string const& target) {
    if (!this->healthCheck()) {
        std::cout << RED << "ScavTrap " << this->getName() << " is dead"
            << RESET << std::endl;
        return;
    } else {
        std::cout << YELLOW << "ScavTrap " << this->getName() << " attacks "
            << target << " causing " << this->getAttackDamage()
            << " points of damage!" << RESET << std::endl;
    }
    this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ScavTrap::guardGate() {
    if (!this->healthCheck()) {
        std::cout << RED << "ScavTrap " << this->getName() << " is dead"
            << RESET << std::endl;
        return;
    }
    std::cout << WHITE << "ScavTrap " << this->getName()
        << " has enterred in Gate keeper mode"
        << RESET << std::endl;
}



