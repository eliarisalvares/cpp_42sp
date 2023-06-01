/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:40:01 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/01 18:53:04 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << WHITE << "ClapTrap Default Constructor called"
        << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
        _energyPoints(10), _attackDamage(0) {
    std::cout << WHITE << "ClapTrap " << this->_name << " created"
        << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& src) {
    std::cout << WHITE << "ClapTrap Copy Constructor called"
        << RESET << std::endl;
    *this = src;
}

ClapTrap::~ClapTrap() {
    std::cout << WHITE << "ClapTrap " << this->_name << " destroyed"
        << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs) {
    std::cout << WHITE << "ClapTrap Assignation operator called"
        << RESET << std::endl;
    if (this != &rhs) {
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }

    return (*this);
}

int ClapTrap::healthCheck(void) {
    if (this->_hitPoints <= 0) {
        std::cout << RED << this->_name << " is dead"
            << RESET << std::endl;
        return (0);
    }
    if (_energyPoints <= 0) {
        std::cout << RED << this->_name << " is out of energy"
            << RESET << std::endl;
        return (0);
    }
    return (1);
}

/**
 * @brief When the ClapTrap attacks another ClapTrap, the number of energy
 * points is reduced by 1, "costing" 1 energy point.
 *
 * @param target std::string const&: the name of the target
 */
void ClapTrap::attack(std::string const& target) {
    if (!this->healthCheck()) {
        return;
    } else {
        std::cout << YELLOW << "ClapTrap " << this->_name << " attack "
            << target << ", causing " << this->_attackDamage
            << " points of damage!" << RESET << std::endl;
        setEnergyPoints(this->_energyPoints - 1);
    }
}

/**
 * @brief When the ClapTrap takes damage, the number of hit points is reduced
 * by the amount of damage specified by the parameter amount.
 *
 * @param amount unsigned int: the amount of damage
 */
void ClapTrap::takeDamage(unsigned int amount) {
    if (this->healthCheck() == 0) {
        return;
    } else {
        std::cout << RED << "ClapTrap " << this->_name << " take "
            << amount << " points of damage!" << RESET << std::endl;
        setHitPoints(this->_hitPoints - amount);
    }
}

/**
 * @brief When the ClapTrap is repaired, the number of hit points is increased
 * by the amount of damage specified by the parameter amount. Also, the number
 * of energy points is reduced by 1, "costing" 1 energy point.
 *
 * @param amount unsigned int: the amount of damage
 */
void ClapTrap::beRepaired(unsigned int amount) {
    if (!this->healthCheck()) {
        return;
    } else {
        std::cout << GREEN << "ClapTrap " << this->_name << " be repaired "
            << amount << " points of damage!" << RESET << std::endl;
        setHitPoints(this->_hitPoints + amount);
        setEnergyPoints(this->_energyPoints - 1);
    }
}

unsigned int ClapTrap::getHitPoints(void) const {
    if (this->_hitPoints < 0) {
        return (0);
    } else {
        return (this->_hitPoints);
    }
}

unsigned int ClapTrap::getEnergyPoints(void) const {
    if (this->_energyPoints < 0) {
        return (0);
    } else {
        return (this->_energyPoints);
    }
}

unsigned int ClapTrap::getAttackDamage(void) const {
    return (this->_attackDamage);
}

std::string ClapTrap::getName(void) const {
    return (this->_name);
}

void ClapTrap::setHitPoints(unsigned int hitPoints) {
    this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
    this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
    this->_attackDamage = attackDamage;
}

void ClapTrap::setName(std::string name) {
    this->_name = name;
}
