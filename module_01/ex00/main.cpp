/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:49:00 by elraira-          #+#    #+#             */
/*   Updated: 2023/04/21 22:50:36 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief your Zombies must be destroyed at the appropriate time (when they are
 * not needed anymore). They must be allocated on the stack or the heap
 * depending on its use: sometimes it’s appropriate to have them on the stack,
 * at other times the heap may a better choice.
 * The new and delete operators are used to allocate and deallocate memory on
 * the heap.
 * To crate a zombie on the stack, we use the constructor or the randomChump()
 * function.
 * @return int 0 if everything went well.
 */

int main(void) {
    std::cout << GREEN << "Creating zombie Elga on heap..."
        << RESET << std::endl;
    Zombie* elga = newZombie("Elga");
    elga->announce();
    delete elga;

    std::cout << GREEN << "Creating zombie Marcel on stack..."
        << RESET << std::endl;
    randomChump("Marcel");

    std::cout << GREEN << "Creating zombie Jorge on stack using constructor..."
        << RESET << std::endl;
    Zombie jorge = Zombie("Jorge");
    jorge.announce();

    return (0);
}
