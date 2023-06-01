/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:41:03 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/01 11:15:37 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_03_EX01_SCAVTRAP_HPP_
#define MODULE_03_EX01_SCAVTRAP_HPP_

#include "ClapTrap.hpp"
#include <iostream> /* std::cout */
#include <string> /* std::string */

/* COLORS */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define WHITE "\e[1;37m"
# define RESET "\033[0m"

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
