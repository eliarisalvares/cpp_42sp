/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:53:45 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/08 12:54:27 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_04_EX00_DOG_HPP_
#define MODULE_04_EX00_DOG_HPP_

#include <iostream> /* std::cout */
#include <string> /* std::string */
#include "Animal.hpp"

/* COLORS */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define BLUE_BACKGROUND "\e[44m"
# define WHITE "\e[1;37m"
# define RESET "\033[0m"

/* DOG CLASS */
class Dog : public Animal {
 public:
    Dog();
    Dog(Dog const& src);
    virtual ~Dog();

    Dog& operator=(Dog const& rhs);

    virtual void makeSound(void) const;
};

#endif  // MODULE_04_EX00_DOG_HPP_
