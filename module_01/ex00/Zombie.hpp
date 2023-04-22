/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:40:40 by elraira-          #+#    #+#             */
/*   Updated: 2023/04/21 22:51:03 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_01_EX00_ZOMBIE_HPP_
# define MODULE_01_EX00_ZOMBIE_HPP_

# include <iostream> /* std::cout */
# include <string> /* std::string */

/* ANSI COLOR CODES */
# define RESET "\033[0m"
# define GREEN "\033[32m"

class Zombie {
 private:
    std::string _name;

 public:
    Zombie(std::string name);
    ~Zombie();
    void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif  /* MODULE_01_EX00_ZOMBIE_HPP_ */
