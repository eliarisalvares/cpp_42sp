/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:43:18 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/01 19:00:52 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    std::cout << BLUE_BACKGROUND << "Game Start" << RESET << std::endl;

    std::cout << std::endl;
    ClapTrap bigTrap("Jorge");
    std::cout << BLUE << "Jorge Hit Points: " << RESET << bigTrap.getHitPoints()
        << std::endl;
    std::cout << BLUE << "Jorge Energy Points: " << RESET
        << bigTrap.getEnergyPoints() << std::endl;
    std::cout << BLUE << "Jorge Attack Damage: " << RESET
        << bigTrap.getAttackDamage() << std::endl;

    std::cout << std::endl;
    ClapTrap smallTrap("Elga");
    std::cout << BLUE << "Elga Hit Points: " << RESET
        << smallTrap.getHitPoints() << std::endl;
    std::cout << BLUE << "Elga Energy Points: " << RESET
        << smallTrap.getEnergyPoints() << std::endl;
    std::cout << BLUE << "Elga Attack Damage: " << RESET
        << smallTrap.getAttackDamage() << std::endl;

    std::cout << std::endl;
    ClapTrap copyTrap(smallTrap);
    std::cout << BLUE << "Elga's Copy Hit Points: " << RESET
        << copyTrap.getHitPoints() << std::endl;
    std::cout << BLUE << "Elga's Copy Energy Points: " << RESET
        << copyTrap.getEnergyPoints() << std::endl;
    std::cout << BLUE << "Elga's Copy Attack Damage: " << RESET
        << copyTrap.getAttackDamage() << std::endl;

    std::cout << std::endl;
    std::cout << BLUE <<  "Setting Jorge Attack Damage to 5" << std::endl;
    bigTrap.setAttackDamage(5);
    bigTrap.attack(smallTrap.getName());
    smallTrap.takeDamage(bigTrap.getAttackDamage());
    std::cout << "Elga Hit Points: " << smallTrap.getHitPoints() << std::endl;
    std::cout << "Jorge Energy Points: " << bigTrap.getEnergyPoints()
        << std::endl;
    std::cout << std::endl;

    smallTrap.attack(bigTrap.getName());
    bigTrap.takeDamage(smallTrap.getAttackDamage());
    std::cout << "Jorge Hit Points: " << bigTrap.getHitPoints() << std::endl;
    std::cout << "Elga Energy Points: " << smallTrap.getEnergyPoints()
        << std::endl;
    std::cout << std::endl;

    smallTrap.beRepaired(5);
    std::cout << "Elga's Hit Points: " << smallTrap.getHitPoints()
        << std::endl;
    std::cout << "Elga's Energy Points: " << smallTrap.getEnergyPoints()
        << std::endl;
    std::cout << std::endl;

    std::cout << BLUE << "Setting CopyTrap Attack Damage to 10" << std::endl;
    copyTrap.setAttackDamage(10);
    copyTrap.attack(smallTrap.getName());
    smallTrap.takeDamage(copyTrap.getAttackDamage());
    std::cout << "Elga Hit Points: " << smallTrap.getHitPoints() << std::endl;
    std::cout << "CopyTrap Energy Points: " << copyTrap.getEnergyPoints()
        << std::endl;
    std::cout << std::endl;

    smallTrap.attack(copyTrap.getName());
    std::cout << std::endl;

    std::cout << BLUE_BACKGROUND << "End of Game" << RESET << std::endl;

    return (0);
}
