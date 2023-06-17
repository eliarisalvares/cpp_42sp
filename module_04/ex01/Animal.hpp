/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:33:40 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/17 19:19:41 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_04_EX01_ANIMAL_HPP_
#define MODULE_04_EX01_ANIMAL_HPP_

#include <iostream> /* std::cout */
#include <string> /* std::string */

/* COLORS */
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

#endif
