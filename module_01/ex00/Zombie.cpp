/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:40:04 by elraira-          #+#    #+#             */
/*   Updated: 2023/02/26 13:44:45 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Construct a new Zombie:: Zombie object
 *
 * @param name The name of the zombie. Must be private.
 */
Zombie::Zombie(std::string name)
	: _name(name)
{
}

/**
 * @brief Destroy the Zombie:: Zombie object.
 * The destructor must announce the zombie's name and a debug message.
 *
 */
Zombie::~Zombie()
{
	std::cout << this->_name << ": I've died..." << std::endl;
}

/**
 * @brief Mandatory method to announce the zombie's name.
 *
 */
void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

