/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:45:32 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/14 21:02:54 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_04_EX00_CAT_HPP_
#define MODULE_04_EX00_CAT_HPP_

#include <iostream> /* std::cout */
#include <string> /* std::string */
#include "Animal.hpp"

/* COLORS */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define BLUE_BACKGROUND "\e[44m"

/* CAT CLASS */
class Cat : public Animal {
 public:
    Cat();
    Cat(Cat const& src);
    virtual ~Cat();
    Cat& operator=(Cat const& rhs);

    virtual void makeSound(void) const;
};

#endif  // MODULE_04_EX00_CAT_HPP_
