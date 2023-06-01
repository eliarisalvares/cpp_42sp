/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:41:03 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/01 18:49:54 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_03_EX01_SCAVTRAP_HPP_
#define MODULE_03_EX01_SCAVTRAP_HPP_

#include <iostream> /* std::cout */
#include <string> /* std::string */
#include "ClapTrap.hpp"

/* SCAVTRAP CLASS */

/* ScavTrap inherits from ClapTrap which means that it will have all the
 * attributes and methods of the ClapTrap class. The ScavTrap is, then, a
 * derived class of the ClapTrap class. */
class ScavTrap : public ClapTrap {
 public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const& src);
    ~ScavTrap();

    ScavTrap& operator=(ScavTrap const& rhs);
    void guardGate(void);
    void attack(std::string const& target);

 private:
};

#endif /* MODULE_03_EX01_SCAVTRAP_HPP_ */
