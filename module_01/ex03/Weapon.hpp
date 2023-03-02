/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:33:51 by elraira-          #+#    #+#             */
/*   Updated: 2023/03/01 23:09:10 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_01_EX03_WEAPON_HPP_
# define MODULE_01_EX03_WEAPON_HPP_

# include <iostream> /* cout, endl */
# include <string> /* string */

class Weapon {
 public:
    Weapon(std::string type);
    ~Weapon(void);
    const std::string& getType(void);
    void setType(std::string type);
 private:
    std::string _type;
};

#endif  // MODULE_01_EX03_WEAPON_HPP_
