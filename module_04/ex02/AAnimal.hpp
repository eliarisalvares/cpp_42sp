/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:06:25 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/14 23:18:51 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_04_EX02_AANIMAL_HPP_
#define MODULE_04_EX02_AANIMAL_HPP_

#include <iostream> /* std::cout */
#include <string> /* std::string */
#include "Brain.hpp"

/* COLORS */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define BLUE_BACKGROUND "\e[44m"
# define WHITE "\e[1;37m"
# define RESET "\033[0m"

/* AANIMAL CLASS */
class AAnimal {
 public:
    AAnimal();
    AAnimal(std::string type);
    AAnimal(AAnimal const& src);
    virtual ~AAnimal();

    AAnimal& operator=(AAnimal const& rhs);

    /* Accessors */
    std::string getType(void) const;

    /* Mutators */
    void setType(std::string type);

    virtual void makeSound(void) const = 0;
    virtual Brain* getBrain(void) const = 0;

 protected:
    std::string _type;
    
};

#endif  // MODULE_04_EX02_AANIMAL_HPP_
