/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:41:03 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/01 23:22:13 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_01_EX03_HUMANB_HPP_
# define MODULE_01_EX03_HUMANB_HPP_

# include <iostream> /* cout, endl */
# include <string> /* string */
# include "Weapon.hpp"

class HumanB {
 public:
    HumanB(std::string name);
    ~HumanB(void);
    void attack(void);
    void setWeapon(Weapon& weapon);
 private:
    std::string _name;
    Weapon* _weapon;
};

#endif  /* MODULE_01_EX03_HUMANB_HPP_ */
