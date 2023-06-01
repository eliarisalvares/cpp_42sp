/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:25:27 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/01 17:01:53 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_03_EX02_CLAPTRAP_HPP_
#define MODULE_03_EX02_CLAPTRAP_HPP_

#include <iostream> /* std::cout */
#include <string> /* std::string */

/* COLORS */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define WHITE "\e[1;37m"
# define RESET "\033[0m"

/* CLAPTRAP CLASS */
class ClapTrap {
 public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(ClapTrap const& src);
    ~ClapTrap();

    ClapTrap& operator=(ClapTrap const& rhs);
    void attack(std::string const& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    /* Accessors */
    unsigned int getHitPoints(void) const;
    unsigned int getEnergyPoints(void) const;
    unsigned int getAttackDamage(void) const;
    std::string getName(void) const;

    /* Mutators */
    void setHitPoints(unsigned int hitPoints);
    void setEnergyPoints(unsigned int energyPoints);
    void setAttackDamage(unsigned int attackDamage);
    void setName(std::string name);

    int healthCheck(void);

 protected:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;
};

#endif  /* MODULE_03_EX02_CLAPTRAP_HPP_ */
