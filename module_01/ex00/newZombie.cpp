/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:46:03 by elraira-          #+#    #+#             */
/*   Updated: 2023/04/21 22:17:41 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Create a new Zombie object and return a pointer to it
 * so it can be used in another function. It allocates memory
 * on the heap which means it must be deleted. We will do this
 * in the main function. To allocate memory on the heap we use the
 * new keyword.
 *
 * @param name The name of the zombie.
 * @return Zombie* A pointer to the new zombie.
 */
Zombie* newZombie(std::string name) {
    Zombie* zombie = new Zombie(name);
    return (zombie);
}

