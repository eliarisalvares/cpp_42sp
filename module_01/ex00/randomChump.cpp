/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:46:56 by elraira-          #+#    #+#             */
/*   Updated: 2023/04/21 22:18:40 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Create a random Zombie object and announce it. Here,
 * the zombie is created on the stack, which means it will be
 * destroyed when the function ends. We don't need to delete it.
 *
 * @param name The name of the zombie.
 */
void randomChump(std::string name) {
    Zombie zombie = Zombie(name);
    zombie.announce();
}
