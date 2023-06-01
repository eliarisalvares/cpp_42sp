/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:19:03 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/01 18:48:47 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_03_EX02_FRAGTRAP_HPP_
#define MODULE_03_EX02_FRAGTRAP_HPP_

#include <iostream> /* std::cout */
#include <string> /* std::string */
#include "ClapTrap.hpp"

/* FLAGTRAP CLASS */
class FragTrap : public ClapTrap {
 public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap const& src);
    ~FragTrap();

    FragTrap& operator=(FragTrap const& rhs);
    void highFivesGuys(void);

 private:
};

#endif /* MODULE_03_EX02_FRAGTRAP_HPP_ */
