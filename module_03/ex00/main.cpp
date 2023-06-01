/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:43:18 by elraira-          #+#    #+#             */
/*   Updated: 2023/05/31 22:34:51 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    ClapTrap bigTrap("Jorge");
    std::cout << BLUE << "Jorge Hit Points: " << RESET << bigTrap.getHitPoints()
        << std::endl;
    std::cout << BLUE << "Jorge Energy Points: " << RESET
        << bigTrap.getEnergyPoints() << std::endl;
    std::cout << BLUE << "Jorge Attack Damage: " << RESET
        << bigTrap.getAttackDamage() << std::endl;
    std::cout << std::endl;

    ClapTrap smallTrap("Elga");
    std::cout << std::endl;

    ClapTrap copyTrap(smallTrap);
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

    return (0);

}


