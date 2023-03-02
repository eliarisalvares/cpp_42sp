/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:07:49 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/01 22:59:20 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    int N = 4;
    std::string name = "Clicker";

    Zombie* horde = zombieHorde(N, name);
    std::cout << "Horde of " << N << " zombies created!" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << "Zombie " << i << " says:" << std::endl;
        horde[i].announce();
    }
    delete[] horde;
    std::cout << "Remaining zombies: " << Zombie::zombieCount << std::endl;
    return (0);
}
