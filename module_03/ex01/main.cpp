/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:34:37 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/01 14:02:19 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
    std::cout << BLUE << "Game Start" << std::endl;

    std::cout << std::endl;
    std::cout << "Create Player ClapTrap" << RESET << std::endl;
    ClapTrap clapTrap("Clappy");

    std::cout << std::endl;
    std::cout << BLUE << "Create Player ScavTrap" << RESET << std::endl;
    ScavTrap scavTrap("Scavy");

    std::cout << std::endl;
    std::cout << BLUE << "Player ClapTrap" << RESET << std::endl;
    std::cout << "Name: " << clapTrap.getName() << std::endl;
    std::cout << "Hit Points: " << clapTrap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clapTrap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << clapTrap.getAttackDamage() << std::endl;

    std::cout << std::endl;
    std::cout << BLUE << "Player ScavTrap" << RESET << std::endl;
    std::cout << "Name: " << scavTrap.getName() << std::endl;
    std::cout << "Hit Points: " << scavTrap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << scavTrap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << scavTrap.getAttackDamage() << std::endl;

    std::cout << std::endl;
    clapTrap.attack(scavTrap.getName());
    scavTrap.takeDamage(clapTrap.getAttackDamage());
    scavTrap.guardGate();
    scavTrap.beRepaired(1);

    std::cout << std::endl;
    scavTrap.attack(clapTrap.getName());
    clapTrap.takeDamage(scavTrap.getAttackDamage());
    scavTrap.guardGate();
    scavTrap.beRepaired(1);

    std::cout << std::endl;
    clapTrap.attack(scavTrap.getName());

    std::cout << std::endl;
    scavTrap.attack(clapTrap.getName());

    std::cout << std::endl;
    std::cout << BLUE << "End of the game" << RESET << std::endl;
    return (0);
}
