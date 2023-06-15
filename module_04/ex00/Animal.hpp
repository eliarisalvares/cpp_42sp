/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:34:50 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/14 20:59:40 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_04_EX00_ANIMAL_HPP_
#define MODULE_04_EX00_ANIMAL_HPP_

#include <iostream> /* std::cout */
#include <string> /* std::string */

/* COLORS */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define BLUE_BACKGROUND "\e[44m"
# define WHITE "\e[1;37m"
# define RESET "\033[0m"

/* ANIMAL CLASS */
class Animal {
 public:
    Animal();
    Animal(std::string type);
    Animal(Animal const& src);
    virtual ~Animal(); /* virtual destructor allows to call the right destructor
                        * for the derived class, guaranteeing that all the
                        * memory allocated for the object is properly released.
                        */

    Animal& operator=(Animal const& rhs);

    /* Accessors */
    std::string getType(void) const;

    /* Mutators */
    void setType(std::string type);

    virtual void makeSound(void) const;

 protected:
    std::string _type;
};

std::ostream& operator<<(std::ostream& os, Animal const& animal);

#endif  // MODULE_04_EX00_ANIMAL_HPP_
