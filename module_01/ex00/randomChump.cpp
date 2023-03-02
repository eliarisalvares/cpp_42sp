/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:46:56 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/01 22:45:29 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Create a random Zombie object and announce it.
 *
 * @param name The name of the zombie.
 */
void randomChump(std::string name) {
    Zombie zombie = Zombie(name);
    zombie.announce();
}
