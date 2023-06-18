/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:31:33 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/17 23:52:55 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_05_EX03_INTERN_HPP
#define MODULE_05_EX03_INTERN_HPP

#include <iostream> /* std::cout */
#include <string> /* std::string */
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/* COLORS */
# define WHITE "\e[1;37m"
# define RESET "\033[0m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"

class AForm; /* Forward declaration to avoid circular dependency */

/* INTERN CLASS */
class Intern {
    class FormNotCreated : public std::exception {
    public:
        const char* what() const throw();
    };

public:
    Intern();
    Intern(Intern const& src);
    ~Intern();

    Intern& operator=(const Intern& rhs);

    /* Member functions */
    AForm* makeForm(std::string const& name, std::string const& target);

private:
    AForm* _makePresidentialPardonForm(std::string const& target);
    AForm* _makeRobotomyRequestForm(std::string const& target);
    AForm* _makeShrubberyCreationForm(std::string const& target);
};

#endif //MODULE_05_EX03_INTERN_HPP
