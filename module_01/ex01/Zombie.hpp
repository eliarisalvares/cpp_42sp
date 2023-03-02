/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:03:52 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/01 23:22:04 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_01_EX01_ZOMBIE_HPP_
# define MODULE_01_EX01_ZOMBIE_HPP_

# include <iostream> /* cout, endl */
# include <string> /* string */

class Zombie {
 public:
    Zombie(void);
    ~Zombie(void);
    void announce(void);
    void setName(std::string name);
    static int zombieCount;
 private:
    std::string _name;
};

Zombie* zombieHorde(int c, std::string name);

#endif  /* MODULE_01_EX01_ZOMBIE_HPP_ */

