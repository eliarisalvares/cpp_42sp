/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:14:03 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/08 13:16:29 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_04_WRONGCAT_HPP
#define MODULE_04_WRONGCAT_HPP

#include <iostream> /* std::cout */
#include <string> /* std::string */
#include "WrongAnimal.hpp"

/* COLORS */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define BLUE_BACKGROUND "\e[44m"
# define WHITE "\e[1;37m"
# define RESET "\033[0m"

/* WRONGCAT CLASS */
class WrongCat : public WrongAnimal {
 public:
    WrongCat();
    WrongCat(WrongCat const& src);
    ~WrongCat();

    WrongCat& operator=(WrongCat const& rhs);

    void makeSound(void) const;
};

#endif  // MODULE_04_WRONGCAT_HPP
