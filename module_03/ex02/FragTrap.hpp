/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:19:03 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/01 14:29:01 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_03_EX02_FLAGTRAP_HPP_
#define MODULE_03_EX02_FLAGTRAP_HPP_

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

#endif /* MODULE_03_EX02_FLAGTRAP_HPP_ */
