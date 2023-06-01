/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:21:52 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/01 14:51:13 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap() {
    std::cout << "FragTrap Default Constructor called" << std::endl;
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    this->setName(name);
    std::cout << "FragTrap " << this->getName() << " created" << std::endl;
}

FragTrap::FragTrap(FragTrap const& src) {
    std::cout << "FragTrap Copy Constructor called" << std::endl;
    *this = src;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->getName() << " destroyed"
        << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const& rhs) {
    if (this != &rhs) {
        this->setName(rhs.getName());
        this->setHitPoints(rhs.getHitPoints());
        this->setEnergyPoints(rhs.getEnergyPoints());
        this->setAttackDamage(rhs.getAttackDamage());
    }
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << WHITE << "High five guys! My name is " << this->getName()
        << RESET << std::endl;
}
