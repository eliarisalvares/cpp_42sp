/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:37:28 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/01 23:22:23 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_01_EX03_HUMANA_HPP_
# define MODULE_01_EX03_HUMANA_HPP_

# include <iostream> /* cout, endl */
# include <string> /* string */
# include "Weapon.hpp"

class HumanA {
 public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA(void);
    void attack(void);
 private:
    std::string _name;
    Weapon& _weapon;
};

#endif  /* MODULE_01_EX03_HUMANA_HPP_ */
