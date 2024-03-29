/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:34:37 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/01 18:48:38 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
    std::cout << BLUE_BACKGROUND << "Game Start" << RESET << std::endl;

    std::cout << std::endl;
    std::cout << BLUE << "Create Player ClapTrap" << RESET << std::endl;
    ClapTrap clapTrap("Clappy");

    std::cout << std::endl;
    std::cout << BLUE << "Create Player ScavTrap" << RESET << std::endl;
    ScavTrap scavTrap("Scavy");

    std::cout << std::endl;
    std::cout << BLUE << "Create Player FragTrap" << RESET << std::endl;
    FragTrap fragTrap("Fraggy");

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
    std::cout << BLUE << "Player FragTrap" << RESET << std::endl;
    std::cout << "Name: " << fragTrap.getName() << std::endl;
    std::cout << "Hit Points: " << fragTrap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << fragTrap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << fragTrap.getAttackDamage() << std::endl;

    std::cout << std::endl;
    clapTrap.attack(scavTrap.getName());
    scavTrap.takeDamage(clapTrap.getAttackDamage());
    scavTrap.guardGate();

    std::cout << std::endl;
    scavTrap.attack(clapTrap.getName());
    clapTrap.takeDamage(scavTrap.getAttackDamage());
    scavTrap.beRepaired(1);

    std::cout << std::endl;
    clapTrap.attack(scavTrap.getName());

    std::cout << std::endl;
    scavTrap.attack(fragTrap.getName());
    fragTrap.takeDamage(scavTrap.getAttackDamage());
    fragTrap.highFivesGuys();

    std::cout << std::endl;
    std::cout << BLUE_BACKGROUND << "End of the game" << RESET << std::endl;
    return (0);
}
